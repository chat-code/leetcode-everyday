#!/usr/bin/env bash

if wget https://leetcode.com/api/problems/algorithms/ -O problems_1.json; then
    python3 clean_json.py
    python3 -m json.tool problems_1.json > problems_2.json
    mv problems_2.json problems.json
else
    echo "wget failed"
fi
