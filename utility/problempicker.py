#!/usr/bin/env python3
from dataclasses import dataclass
from datetime import date, timedelta
from pathlib import Path
from typing import *
import subprocess

SUB_DIRS = [".", "past"]
README_TEMPLATE = "./utility/README_template.md"
README_NEW = "READEME.md"
TRUE_ALIAS = ("", "t", "T", "True")


@dataclass
class ReadmeInfo:
    dir: Path
    name: str
    content: str
    rid: int

    def get_path(self):
        return self.dir / self.name


def check_cwd():
    git_dir = Path(".git")
    if not git_dir.exists():
        raise FileNotFoundError("Sub-dir '.git' not found. Run this script at the root-dir of repository.")


def get_past_problems(sub_dirs: List[str]) -> Tuple:
    dates: List[date] = []
    lc_ids: List[int] = []
    for subdir in sub_dirs:
        for x in Path(subdir).glob("*_*"):
            if x.is_dir():
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


def get_new_date(dates: List[date]) -> date:
    return max(dates) + timedelta(days=1)


def get_new_dir_name(dates: List[date], info: Dict) -> str:
    new_id = info["id"]
    next_date = get_new_date(dates)
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

    # get title from link
    title = link.split("/")[-1]
    title = title.replace("-", " ").title()
    # handle special words in title
    for s in (" Ii", " Iii"):
        if title.endswith(s):
            title = title[:-len(s)] + s.upper()

    level = input("Input level (E/[M]/H): ")
    if level == "":
        level = "M"
    level = {"E": "Easy", "M": "Medium", "H": "Hard"}[level]
    info["title"] = title
    info["level"] = level


def create_readme(md_template: str, md_new: str, dirname: str, info: Dict, from_input=True) -> ReadmeInfo:
    if from_input:
        get_problem_info(info)
    new_dir = Path(dirname)

    with open(md_template) as f:
        md_template_text = f.read()
    # new_md_path = new_dir / md_new
    md_new_text = md_template_text.format(**info)

    print("=" * 40)
    print(md_new_text)
    print("=" * 40)
    return ReadmeInfo(new_dir, md_new, md_new_text, info['id'])


def commit_readme(rm: ReadmeInfo, auto=False):
    is_confirmed = "T" if auto else input(f"Wirte to file ./{rm.dir}/{rm.name}? [T]/F ")
    if is_confirmed in TRUE_ALIAS:
        rm.dir.mkdir()
        with rm.get_path().open('w') as f:
            f.write(rm.content)
        is_auto_git = "T" if auto else input("Auto commit? [T]/F ")
        if is_auto_git in TRUE_ALIAS:
            subprocess.run(["git", "add", rm.dir.name])
            subprocess.run(["git", "commit", "-m", "pick " + str(rm.rid)])


def hand_pick():
    # config
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
    readme = create_readme(README_TEMPLATE, README_NEW, dirname, info)
    commit_readme(readme)


if __name__ == '__main__':
    hand_pick()
