/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 97.43 % of cpp submissions
// Your memory usage beats 78.84 % of cpp submissions (16.8 MB)

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int single = 0;
    for (auto&& a : nums) {
      single ^= a;
    }
    return single;
  }
};
// @lc code=end

