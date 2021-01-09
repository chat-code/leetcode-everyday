/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 * 
 * 設計好輔助函數即可
 * 
 * 注意 & 和 == 的優先級
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    using VI = vector<int>;
    bool pre10(int a) {
        return (a & 0b11000000) == 0b10000000;
    }
    int cntb(int a) {
        int a1 = 0b10000000, b1 = 0b00000000,
            a2 = 0b11100000, b2 = 0b11000000,
            a3 = 0b11110000, b3 = 0b11100000,
            a4 = 0b11111000, b4 = 0b11110000;
        if ((a & a1) == b1) return 1;
        else if ((a & a2) == b2) return 2;
        else if ((a & a3) == b3) return 3;
        else if ((a & a4) == b4) return 4;
        else return -1;
    }
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int i = 0; i < data.size(); i++) {
            int t = data[i] & ((1<<8) - 1);
            if (cnt > 0) {
                bool c = pre10(t);
                if (!c) return false;
                else {
                    cnt--;
                    continue;
                }
            }
            int b = cntb(t);
            if (b == -1) return false;
            if (b == 1) continue;
            cnt = b - 1;
        }

        return cnt == 0;
    }
};
// @lc code=end

