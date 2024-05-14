/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 * 
 * 觀察二進制的變化方式，可以得到遞推的規律
 * 遇到 2^k 形式的數字，那麼它後面的數字可以由 n-2^k 的轉化過來；一直到 2^(k+1)
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    using VI = vector<int>;
    vector<int> countBits(int num) {
        VI res(num+1, 0);
        if (num == 0) return res;
        res[1] = 1;
        int b = 1;
        for (int i = 2; i <= num; i++) {
            if (i == (1<<(1+b))) {
                ++b;
            }
            int t = (1 << b);
            if (i > t) {
                res[i] = res[i-t]+1;
            } else {
                res[i] = 1;
            }
        }
        return res;
    }
};
// @lc code=end

