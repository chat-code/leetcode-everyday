/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 74.85 % of cpp submissions
// Your memory usage beats 80.31 % of cpp submissions (35.6 MB)

class Solution {
public:
  bool isIdealPermutation(vector<int>& nums) {
    if (nums.size() <= 2) return true;
    int ma = nums[0];
    for (int i = 2; i < nums.size(); ++i) {
      if (ma > nums[i]) return false;
      ma = std::max(ma, nums[i - 1]);
    }
    return true;
  }
};
// @lc code=end

// 评价：
// 草了，medium 就这就这？
