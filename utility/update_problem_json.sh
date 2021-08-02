#!/usr/bin/env bash

wget https://leetcode.com/api/problems/algorithms/ -O problems.json
python3 clean_json.py
python3 -m json.tool problems.json > problems_1.json
mv problems_1.json problems.json
