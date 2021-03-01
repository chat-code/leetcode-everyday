/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
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
    VI incr(VI& a) {
        VI c;
        int t = 1;
        for (int i = 0; i < int(a.size()); ++i) {
            t += a[i];
            c.push_back(t % 10);
            t /= 10;
        }
        if (t) c.push_back(t);
        reverse(c.begin(), c.end());
        return c;
    }
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        return incr(digits);
    }
};
// @lc code=end

