/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
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

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    VI mul(VI& a, VI& b) {
        VI c;
        int t = 0;
        for (int i = 0; i < a.size(); ++i) {
            t = 0;
            for (int j = 0; j < b.size(); ++j) {
                t = t + a[i] * b[j];
                if (i + j >= c.size()) {
                    c.push_back(t % 10);
                    t /= 10;
                } else {
                    c[i + j] += t;
                    t = c[i + j] / 10;
                    c[i + j] %= 10;
                }
            }
            if (t) c.push_back(t);
        }
        while (c.size() > 1 && !c.back()) c.pop_back();
        return c;
    }
    string multiply(string num1, string num2) {
        VI a, b, c;
        for (int i = num1.size() - 1; i >= 0; --i) a.push_back(num1[i] - '0');
        for (int i = num2.size() - 1; i >= 0; --i) b.push_back(num2[i] - '0');
        c = mul(a, b);
        string r;
        for (int i = c.size() - 1; i >= 0; --i) r = r + char('0' + c[i]);
        return r;
    }
};
// @lc code=end

