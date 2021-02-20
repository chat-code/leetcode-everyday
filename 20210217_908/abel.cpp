/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */
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

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int n = A.size(), x = INT_MAX, y = INT_MIN;
        for (auto &i : A) {
            if (x > i) x = i;
            if (y < i) y = i;
        }
        int t = abs(x - y);
        K <<= 1;
        if (t > K) return t - K;
        else return 0;
    }
};
// @lc code=end

