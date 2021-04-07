/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 91.8 % of cpp submissions
// Your memory usage beats 45.07 % of cpp submissions (13.2 MB)
#include <numeric>

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int ma, subsum;
    ma = subsum = nums.front();

    for (int i = 1; i < nums.size(); ++i) {
      if (subsum < 0)
        subsum = nums[i];
      else
        subsum += nums[i];
      ma = std::max(subsum, ma);
    }

    return ma;
  }
};
// @lc code=end

