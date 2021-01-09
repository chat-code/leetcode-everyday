/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 * 
 * 找規律
 * 例如 k=5
 * 這樣構造：1, 1+5, 1+5-4, 1+5-4+3, 1+5-4+3-2, 1+5-4+3-2+1
 *         1, 6, 2, 5, 3, 4
 * 這樣可以構造出 1~6，接下來從 k+2=7 開始遞增填充即可
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    using VI = vector<int>;
    vector<int> constructArray(int n, int k) {
        VI res(n, 0);
        int cur = 1, s = 1, sz = 0;
        res[sz++] = 1;
        for (int i = k; i >= 1; --i) {
            cur += i * s;
            s *= -1;
            res[sz++] = cur;
        }
        for (int i = k+2; i <= n; ++i) {
            res[sz++] = i;
        }

        return res;
    }
};
// @lc code=end

