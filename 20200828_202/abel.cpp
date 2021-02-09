/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
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
    int sum(int n) {
        int r = 0, t = 0;
        while (n) {
            t = n % 10;
            r += t * t;
            n /= 10;
        }
        return r;
    }
    bool isHappy(int n) {
        int a[1233] {};
        while (true) {
            n = sum(n);
            if (n == 1) return true;
            if (a[n]) return false;
            a[n] = 1;
        }
        return true;
    }
};
// @lc code=end

