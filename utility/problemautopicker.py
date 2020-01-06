from datetime import date
from random import choice

from utility.problem import Problem
from utility.problempicker import get_past_problems, check_cwd, create_readme, commit_readme, \
    README_TEMPLATE, README_NEW, SUB_DIRS, TRUE_ALIAS, get_new_date


def random_generate(last_problem: Problem = None) -> Problem:
    check_cwd()
    dates, lc_ids = get_past_problems(SUB_DIRS)
    if last_problem is not None: dates.append(last_problem.new_date)
    problems_to_do = list(filter(lambda x: x.pid not in lc_ids, Problem.from_file(get_new_date(dates))))
    chosen: Problem = choice(problems_to_do)
    return chosen


def random_pick():
    chosen = random_generate()
    commit_readme(
        create_readme(README_TEMPLATE, README_NEW, chosen.get_new_dir_name(), chosen.to_dict(), from_input=False))


def choose_pick():
    check_cwd()
    pid = int(input('choose problem id:'))
    dates, lc_ids = get_past_problems(SUB_DIRS)
    problems_to_do = list(filter(lambda x: x.pid not in lc_ids, Problem.from_file(get_new_date(dates))))
    if pid in (i.pid for i in problems_to_do):
        chosen: Problem = next(i for i in problems_to_do if i.pid == pid)
        commit_readme(
            create_readme(README_TEMPLATE, README_NEW, chosen.get_new_dir_name(), chosen.to_dict(), from_input=False))
    elif pid in lc_ids:
        print("problem have been chosen")
    else:
        print("problem id is not in the database")


def week_pick():
    ps = []
    lp = None
    for _ in range(7):
        p = random_generate(lp)
        ps.append(p)
        lp = p
    for p in ps:
        print(p.get_new_dir_name())
    rms = [create_readme(README_TEMPLATE, README_NEW, p.get_new_dir_name(), p.to_dict(), from_input=False) for p in ps]
    comfirmed = input(f"write to the above files and commit? [T]/F: ")
    if comfirmed in TRUE_ALIAS:
        for readme in rms:
            commit_readme(readme, auto=True)


if __name__ == "__main__":
    random_pick()
