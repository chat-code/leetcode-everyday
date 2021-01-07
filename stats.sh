#!/usr/bin/env bash

# find . -type f -name '*.*' | xargs basename | sort | uniq
names=(duangduang Saigyouji-Yuyuko dd Alex Kamikakushi jordi abel)
tmp_file="__tmp__file__stats"

for name in ${names[@]}
do
    cnt=`find . -type f -name "$name.*" | wc -l | xargs`
    printf "%3d : $name\n" $cnt >> $tmp_file
done
sort -k 1 -n -r $tmp_file
rm ./$tmp_file
