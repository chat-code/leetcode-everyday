#!/usr/bin/env bash

# Add a flag for only cleaning and formatting
ONLY_CLEAN_FORMAT=false
while getopts ":c" opt; do
    case ${opt} in
    c) # process option c
        ONLY_CLEAN_FORMAT=true
        ;;
    \?)
        echo "Usage: cmd [-c]"
        ;;
    esac
done

# Get JSON from leetcode.com
get_leetcode_json() {
    wget --user-agent="Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.97 Safari/537.36" https://leetcode.com/api/problems/algorithms/ -O problems_full.json
}

# Download the JSON from the URL
if [ "$ONLY_CLEAN_FORMAT" = false ]; then
    if get_leetcode_json; then
        echo "Download successful"
        mv problems_full.json problems_in.json
    else
        echo "wget failed"
        rm problems_full.json
        exit 1
    fi
fi

# Use clean_json.py to clean the JSON
python3 clean_json.py --input problems_in.json
