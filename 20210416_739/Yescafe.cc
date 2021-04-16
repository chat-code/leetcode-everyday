/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include <vector>
using std::vector;

// @lc code=start
// Runtime: 52 ms, faster than 87.48% of C++ online submissions for Daily Temperatures.
// Memory Usage: 39.9 MB, less than 95.86% of C++ online submissions for Daily Temperatures.

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& t) {
    std::vector<int> ret(t.size(), 0);
    std::vector<int> stack;
    for (int i = t.size() - 1; i >= 0; --i) {
      while (!stack.empty() && t[stack.back()] <= t[i])
        stack.pop_back();
      if (stack.empty()) {
        ret[i] = 0;
      } else {
        ret[i] = stack.back() - i;
      }
      stack.push_back(i);
    }
    return ret;
  }
};
// @lc code=end

