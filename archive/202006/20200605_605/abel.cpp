/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 * 
 * 判斷前一個位置和後一個位置爲 0 即可
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    using VI = vector<int>;
    bool canPlaceFlowers(vector<int>& a, int n) {
        int len = a.size();
        for (int i = 0; i < len; ++i) {
            if (n <= 0) return true;
            if (a[i] == 1) continue;
            int pre = i-1, nex = i+1;
            if (pre < 0 || (pre >= 0 && a[pre] == 0)) {
                if (nex >= len || (nex < len && a[nex] == 0)) {
                    a[i] = 1;
                    n--;
                }
            }
        }
        return n == 0;
    }
};
// @lc code=end

