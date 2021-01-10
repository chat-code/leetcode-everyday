/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 * 
 * 找規律，遞推公式：
 * f(2k+1) = f(2k) = 2*(k+1-f(k))
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
#include <cmath>
#include <cstdlib>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n & 1) n--;
        int k = n/2;
        return 2 * (k + 1 - lastRemaining(k));
    }
};
// @lc code=end

