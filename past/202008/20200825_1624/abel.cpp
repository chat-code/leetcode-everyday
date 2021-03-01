/*
 * @lc app=leetcode.cn id=1624 lang=cpp
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;


class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        int pos[26] {};
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            int j = i + 1;
            if (pos[c - 'a']) {
                res = max(res, j - 1 - pos[c-'a']);
            } else {
                pos[c-'a'] = j;
            }
        }
        return res;
    }
};
// @lc code=end

