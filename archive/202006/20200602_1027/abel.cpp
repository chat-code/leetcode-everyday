/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 * 
 * d[i][g] 表示以 i 爲結尾，公差爲 g 的等差數列的最大長度
 * d[i][g] = max(d[0..j][g]) j<i
 * 
 * p[i][g] 處理公差爲負數的情況
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
const int N = 2009, M = 10009;
int d[N][M], p[N][M];
class Solution {
public:
    using VI = vector<int>;

    int longestArithSeqLength(vector<int>& a) {
        memset(d, 0, sizeof(d));
        memset(p, 0, sizeof(p));
        int n = a.size();
        int res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int g = a[i] - a[j];
                if (g >= 0) {
                    if (d[j][g] == 0) d[j][g] = 1;
                    if (d[i][g] == 0) d[i][g] = 1;
                    d[i][g] = max(d[i][g], d[j][g] + 1);
                    res = max(res, d[i][g]);
                } else {
                    g = -g;
                    if (p[j][g] == 0) p[j][g] = 1;
                    if (p[i][g] == 0) p[i][g] = 1;
                    p[i][g] = max(p[i][g], p[j][g] + 1);
                    res = max(res, p[i][g]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

