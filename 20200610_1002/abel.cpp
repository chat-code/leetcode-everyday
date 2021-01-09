/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 * 
 * 數 26 個字母在每個單詞中出現次數的最小值即可
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    using VS = vector<string>;
    vector<string> commonChars(vector<string>& a) {
        int cnts[26], tmp[26];
        memset(cnts, 0x3f3f3f3f, sizeof(cnts));
        for (int i = 0; i < a.size(); i++) {
            memset(tmp, 0, sizeof(tmp));
            for (int j = 0; j < a[i].length(); ++j) {
                tmp[a[i][j]-'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                cnts[j] = min(cnts[j], tmp[j]);
            }
        }
        VS res;
        for (int i = 0; i < 26; ++i) {
            string t;
            if (cnts[i]) t += char('a' + i);
            while (cnts[i]--) {
                res.push_back(t);
            }
        }
        return res;
    }
};
// @lc code=end

