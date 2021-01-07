/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int ca = 0, cb = 0;
        int lena = int(s1.length());
        for (int i = 0; i < lena; i++) {
            if (s1[i] == s2[i]) continue;
            if (s1[i] == 'x' && s2[i] == 'y') ca++;
            else cb++;
        }
        if (ca < cb) swap(ca, cb);

        int res = 0;

        int cc = ca - cb;
        if (cc & 1) return -1;

        if (cb & 1) {
            res += cb/2;
            cb = 1;
            if (ca % 2 == 0) return -1;
            ca--;
            res += ca/2;
            res += 2;
        } else {
            res = ca / 2 + cb / 2;
        }
        return res;
    }
};
// @lc code=end

