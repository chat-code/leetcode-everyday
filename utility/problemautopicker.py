import json
from dataclasses import dataclass
from random import choice
from typing import Dict

from utility.problempicker import get_past_problems, check_cwd, get_new_dir_name, create_readme, commit_readme, \
    README_TEMPLATE, README_NEW, SUB_DIRS, TRUE_ALIAS

PROBLEM_URL_PREFIX = "https://leetcode.com/problems/"
ALL_PROBLEM_URL = "https://leetcode.com/api/problems/all/"


@dataclass
class Problem:
    pid: int
    title: str
    url: str
    difficulty: str

    def to_dict(self):
        return {
            'id': self.pid,
            'date': None,
            'title': self.title,
            'link': self.url,
            'level': self.difficulty
        }

    @classmethod
    def from_dict(cls, info: Dict):
        dif = {1: 'Easy', 2: 'Medium', 3: 'Hard'}[info['difficulty']['level']]
        stat = info['stat']
        return cls(stat['question_id'], stat['question__title'], PROBLEM_URL_PREFIX + stat['question__title_slug'], dif)

    @classmethod
    def from_file(cls):
        with open("utility/problems.json") as fp:
            for info in json.load(fp)['stat_status_pairs']:
                if not info['paid_only']:
                    yield cls.from_dict(info)


def random_generate():
    check_cwd()
    dates, lc_ids = get_past_problems(SUB_DIRS)
    problems_to_do = list(filter(lambda x: x.pid not in lc_ids, Problem.from_file()))
    chosen: Problem = choice(problems_to_do)
    info = chosen.to_dict()
    dirname = get_new_dir_name(dates, info)
    return create_readme(README_TEMPLATE, README_NEW, dirname, info, from_input=False)


def random_pick():
    commit_readme(random_generate())


def choose_pick():
    check_cwd()
    pid = int(input('choose problem id:'))
    dates, lc_ids = get_past_problems(SUB_DIRS)
    problems_to_do = list(filter(lambda x: x.pid not in lc_ids, Problem.from_file()))
    if pid in (i.pid for i in problems_to_do):
        chosen: Problem = next(i for i in problems_to_do if i.pid == pid)
        info = chosen.to_dict()
        dirname = get_new_dir_name(dates, info)
        commit_readme(create_readme(README_TEMPLATE, README_NEW, dirname, info, from_input=False))
    elif pid in lc_ids:
        print("problem have been chosen")
    else:
        print("problem id is not in the database")


def week_pick():
    ps = [random_generate() for i in range(7)]
    for p in ps:
        print(p.get_path())
    comfirmed = input(f"write to the above files and commit? [T]/F")
    if comfirmed in TRUE_ALIAS:
        for p in ps:
            commit_readme(p, auto=True)


if __name__ == "__main__":
    random_pick()
