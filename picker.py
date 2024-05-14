#!/usr/bin/env python3

import argparse

from utility.problemautopicker import random_pick, choose_pick, random_generate, week_pick


# parse CLI options
parser = argparse.ArgumentParser(description='Pick one leetcode problem a day.')
parser.add_argument('type', choices=['choose', 'random', 'week'],
                    help='how to pick a problem?')
parser.add_argument('--past', metavar='max_past_days', type=int, default=30,
                    help='max number of past days (default: 30)')
args = parser.parse_args()


if __name__ == "__main__":
    if args.type == 'choose':
        choose_pick(max_past_days=args.past)
    elif args.type == 'random':
        random_pick(max_past_days=args.past)
    elif args.type == "week":
        week_pick()
