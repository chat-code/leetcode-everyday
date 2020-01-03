import json
from dataclasses import dataclass
from random import choice
from typing import Dict

from utility.problempicker import get_past_problems, check_cwd, get_new_dir_name, create_readme

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
        dif = {1: 'easy', 2: 'medium', 3: 'hard'}[info['difficulty']['level']]
        stat = info['stat']
        return cls(stat['question_id'], stat['question__title'], PROBLEM_URL_PREFIX + stat['question__title_slug'], dif)

    @classmethod
    def from_file(cls):
        with open("utility/problems.json") as fp:
            for info in json.load(fp)['stat_status_pairs']:
                if not info['paid_only']:
                    yield cls.from_dict(info)


def random_pick():
    SUB_DIRS = [".", "past"]
    README_TEMPLATE = "./utility/README_template.md"
    README_NEW = "READEME.md"
    TRUE_ALIAS = ("", "t", "T", "True")
    check_cwd()
    dates, lc_ids = get_past_problems(SUB_DIRS)
    problems_to_do = list(filter(lambda x: x.pid not in lc_ids, Problem.from_file()))
    chosen: Problem = choice(problems_to_do)
    info = chosen.to_dict()
    dirname = get_new_dir_name(dates, info)
    create_readme(README_TEMPLATE, README_NEW, dirname, info, TRUE_ALIAS, from_input=False)


if __name__ == "__main__":
    random_pick()
