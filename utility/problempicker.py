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


def check_repetition(new_id: int, ids: List[int]):
    if new_id in ids:
        raise ValueError(f"Problem {new_id} has been picked before.")


def get_new_dir_name(dates: List[date], new_id: int) -> str:
    next_date = max(dates) + timedelta(days=1)
    dirname = f"{next_date.year}{next_date.month}{next_date.day}_{new_id}"
    return dirname


def get_id(ask: str):
    return int(input(ask.format(field="id")))


def get_problem_info(keywords_full: Sequence[str], questions: List[Tuple]) -> Dict[str, str]:
    kv = {k: "{" + k + "}" for k in keywords_full}
    for k, v in questions:
        kv[k] = input(v)
    return kv


def get_editor() -> str:
    program = input("Provide editor used to open README.md file (Default is 'code'): ")
    if program == "":
        program = "code"
    return program


def create_readme(dirname: str, template: str, keys_full: Sequence[str], keys_required: Sequence[str]) -> None:
    questions = [(k, ASK.format(field=k)) for k in keys_required]
    keywords = get_problem_info(keys_full, questions)
    program = get_editor()

    p = Path(dirname)
    p.mkdir()

    with open(template) as f:
        md_template = f.read()
    p = p / "README.md"
    with p.open('w') as f:
        f.write(md_template.format(**keywords))

    subprocess.run([program, str(p)])


if __name__ == '__main__':
    # config
    SUB_DIRS = [".", "past"]
    README_TEMPLATE = "./utility/README_template.md"
    KEYS_FULL = ("title", "link", "level", "topics", "description", "example", "note", "constraints")
    KEYS_REQUIRED = ("title", "link", "level")
    ASK = "Provide problem {field}: "

    # check current working directory
    check_cwd()

    # get new id, check if picked
    new_id = get_id(ASK)
    dates, lc_ids = get_past_problems(SUB_DIRS)
    check_repetition(new_id, lc_ids)

    # get new dirname
    dirname = get_new_dir_name(dates, new_id)

    # get more problem info and create new README.md
    create_readme(dirname, README_TEMPLATE, KEYS_FULL, KEYS_REQUIRED)
