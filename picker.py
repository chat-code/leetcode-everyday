import getopt
import sys

from utility.problemautopicker import random_pick, choose_pick, random_generate, week_pick
from sys import argv

ARGS = ['choose', 'random', 'week']

if __name__ == "__main__":
    if len(argv) > 1:
        arg = argv[1]
        if arg not in ARGS:
            print('picker.py [choose|random|week]')
            sys.exit(2)
        elif arg == 'choose':
            choose_pick()
        elif arg == 'random':
            random_pick()
        elif arg == "week":
            week_pick()
    else:
        choose_pick()
