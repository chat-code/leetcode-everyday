/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 * 
 * 使用 C++ stringstream 即可
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string tmp, res;
        vector<string> v;
        while (ss >> tmp) {
            v.push_back(tmp);
        }
        reverse(v.begin(), v.end());
        if (v.size() == 0) return res;
        res = v[0];
        for (int i = 1; i < v.size(); i++) {
            res = res + " " + v[i];
        }
        return res;
    }
};
// @lc code=end

