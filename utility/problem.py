import json
from dataclasses import dataclass
from datetime import date
from typing import Dict

PROBLEM_URL_PREFIX = "https://leetcode.com/problems/"
ALL_PROBLEM_URL = "https://leetcode.com/api/problems/all/"


@dataclass
class Problem:
    pid: int
    title: str
    url: str
    difficulty: str
    new_date: date

    def to_dict(self):
        return {
            'id': self.pid,
            'date': self.new_date,
            'title': self.title,
            'link': self.url,
            'level': self.difficulty
        }

    @classmethod
    def from_dict(cls, info: Dict, new_date: date):
        dif = {1: 'Easy', 2: 'Medium', 3: 'Hard'}[info['difficulty']['level']]
        stat = info['stat']
        return cls(stat['frontend_question_id'], stat['question__title'], PROBLEM_URL_PREFIX + stat['question__title_slug'], dif,
                   new_date)

    @classmethod
    def from_file(cls, new_date: date):
        with open("utility/problems.json") as fp:
            for info in json.load(fp)['stat_status_pairs']:
                if not info['paid_only']:
                    yield cls.from_dict(info, new_date)

    def get_new_dir_name(self) -> str:
        new_date_str = str(self.new_date).replace("-", "")
        dirname = f"{new_date_str}_{self.pid}"
        return dirname
