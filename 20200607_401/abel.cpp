/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 * 
 * 直接枚舉所有小時和分鐘的組合，然後判斷 1 的個數是否符合題意即可
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    using VI = vector<int>;
    using VS = vector<string>;

    int cn1(int a) {
        int r = 0;
        while (a) {
            r += (a & 1);
            a >>= 1;
        }
        return r;
    }

    VS foo(int num) {
        VS res;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                int c = cn1(i) + cn1(j);
                if (c != num) continue;

                ostringstream oss;
                oss << i << ':';
                if (j < 10) oss << '0';
                oss << j;
                string s = oss.str();
                
                res.push_back(s);
            }
        }
        return res;
    }

    vector<string> readBinaryWatch(int num) {
        return foo(num);
    }
};
// @lc code=end

