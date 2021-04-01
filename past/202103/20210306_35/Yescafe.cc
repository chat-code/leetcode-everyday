/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
// Your runtime beats 90.05 % of cpp submissions
// Your memory usage beats 92.04 % of cpp submissions (9.5 MB)

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    if (target <= nums.front()) return 0;
    if (target > nums.back())   return nums.size();
    int lo = 0, hi = nums.size() - 1;
    int mid;

    while (lo < hi) {
      mid = (lo + hi) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[mid] < target && target <= nums[mid + 1])
        return mid + 1;
      if (target < nums[mid])
        hi = mid;
      if (nums[mid + 1] < target)
        lo = mid;
    }

    return mid;
  }
};
// @lc code=end

// Test cases:
// [1,3,5,6]\n5\n[1,3,5,6]\n2\n[1,3,5,6]\n7\n[1,3,5,6]\n0\n[1]\n0\n[1,3]\n2
