#!/usr/bin/env python3

from datetime import date, timedelta
from pathlib import Path
from typing import *
import subprocess


def check_cwd():
    git_dir = Path(".git")
    if not git_dir.is_dir():
        raise FileNotFoundError("Sub-dir '.git' not found. Run this script at the root-dir of repository.")


def get_past_problems(sub_dirs: List[str]) -> Tuple:
    dates: List[date] = []
    lc_ids: List[int] = []
    for subdir in sub_dirs:
        for x in Path(subdir).glob("*_*"):
            dir_name = str(x.relative_to(subdir))
            pick_date, lc_id = dir_name.split('_')
            dates.append(date(year=int(pick_date[:4]),
                              month=int(pick_date[4:6]),
                              day=int(pick_date[6:])))
            lc_ids.append(int(lc_id))
    return dates, lc_ids


def check_repetition(info: Dict, ids: List[int]):
    new_id = info["id"]
    if new_id in ids:
        raise ValueError(f"Problem {new_id} has been picked before.")


def get_new_dir_name(dates: List[date], info: Dict) -> str:
    new_id = info["id"]
    next_date = max(dates) + timedelta(days=1)
    # print(f"Pick problem {new_id} for date {next_date}. Continuing ...")
    date = str(next_date).replace("-", "")
    dirname = f"{date}_{new_id}"
    info["date"] = date
    return dirname


def get_id(info: Dict):
    info["id"] = int(input("Input id: "))


def get_problem_info(info: Dict):
    link = input("Input link: ")
    info["link"] = link
    
    if link[-1] == "/":
        link = link[:-1]
    title = link.split("/")[-1]
    title = title.replace("-", " ").title()
    
    level = input("Input level (E/[M]/H): ")
    if level == "":
        level = "M"
    level = {"E": "Easy", "M": "Medium", "H": "Hard"}[level]
    info["title"] = title
    info["level"] = level


def create_readme(md_template: str, md_new: str, dirname: str, info: Dict, true_alias: Tuple, from_input=True) -> None:
    if from_input:
        get_problem_info(info)
    new_dir = Path(dirname)

    with open(md_template) as f:
        md_template_text = f.read()
    new_md_path = new_dir / md_new
    md_new_text = md_template_text.format(**info)
    
    print("=" * 40)
    print(md_new_text)
    print("=" * 40)
    
    is_confirmed = input(f"Wirte to file ./{dirname}/{md_new}? [T]/F ")
    if is_confirmed in true_alias:
        new_dir.mkdir()
        with new_md_path.open('w') as f:
            f.write(md_new_text)
        
        is_auto_git = input("Auto commit? [T]/F ")
        if is_auto_git in true_alias:
            subprocess.run(["git", "add", dirname])
            subprocess.run(["git", "commit", "-m", "pick " + str(info["id"])])


if __name__ == '__main__':
    # config
    SUB_DIRS = [".", "past"]
    README_TEMPLATE = "./utility/README_template.md"
    README_NEW = "READEME.md"
    TRUE_ALIAS = ("", "t", "T", "True")
    info = {}

    # check current working directory
    check_cwd()

    # get new id, check if picked
    get_id(info)
    dates, lc_ids = get_past_problems(SUB_DIRS)
    check_repetition(info, lc_ids)

    # get new dirname
    dirname = get_new_dir_name(dates, info)

    # get more problem info and create new README.md
    create_readme(README_TEMPLATE, README_NEW, dirname, info, TRUE_ALIAS)
