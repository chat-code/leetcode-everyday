#!/usr/bin/env python3

import argparse
import datetime
from pathlib import Path
import subprocess


# def parse_command_args():
#     arg_parser = argparse.ArgumentParser(description="Pick a leetcode problem.")
#     arg_parser.add_argument("id",
#                             type=int,
#                             help="problem id")
#     # arg_parser.add_argument("-l", "--link",
#     #                         help="link to leetcode.com")
#     # arg_parser.add_argument("-t", "--title",
#     #                         help="title of picked problem")
#     # arg_parser.add_argument("-p", "--program",
#     #                         help="cli program used to open README.md")
#     return arg_parser.parse_args()

def check_cwd():
    git_dir = Path(".git")
    if not git_dir.is_dir():
        raise FileNotFoundError("Sub-dir '.git' not found. Run this script at the root-dir of reposity.")


def get_past_problems(subdirs):
    dates = []
    lc_ids = []
    for subdir in subdirs:
        for x in Path(subdir).glob("*_*"):
            dir_name = str(x.relative_to(subdir))
            date, lc_id = dir_name.split('_')
            dates.append(datetime.date(year=int(date[:4]), 
                                       month=int(date[4:6]), 
                                       day=int(date[6:])))
            lc_ids.append(int(lc_id))
    return dates, lc_ids


def check_repetition(id, ids):
    if id in ids:
        raise ValueError(f"Problem {id} has been picked before.")


def get_next_date(dates):
    latest_date = dates[0]
    for d in dates:
        if latest_date < d:
            latest_date = d
    return latest_date + datetime.timedelta(days=1)


def pick_problem(date: datetime, id: int):
    dirname = f"{date.year}{date.month}{date.day}_{id}"
    return dirname


def get_id(ask):
    return input(ask.format(field="id"))


def get_problem_info(keywords_full, questions):
    kv = {k : "{"+k+"}" for k in keywords_full}
    for k, v in questions:
        kv[k] = input(v)
    return kv


def get_editor():
    program = input("Provide editor used to open README.md file (Default is 'code'): ")
    if program == "":
        program = "code"
    return program


def create_readme(dirname, template, keys_full, keys_required):
    print()
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
    KEYS_FULL = ("title", "link", "level", "topics", "description", "example", "note")
    KEYS_REQUIRED = ("title", "link")
    ASK = "Provide problem {field}: "
    
    # check current working directory
    check_cwd()
    
    # get new id, check if picked
    new_id = get_id(ASK)
    dates, lc_ids = get_past_problems(SUB_DIRS)
    check_repetition(new_id, lc_ids)
    
    # get new dirname
    next_date = get_next_date(dates)
    dirname = pick_problem(next_date, new_id)
    
    # get more problem info and create new README.md
    create_readme(dirname, README_TEMPLATE, KEYS_FULL, KEYS_REQUIRED)
