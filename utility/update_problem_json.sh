#!/usr/bin/env bash

wget https://leetcode.com/api/problems/algorithms/ -O problems.json
python3 clean_json.py
