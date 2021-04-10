/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 49.19 % of cpp submissions
// Your memory usage beats 59.63 % of cpp submissions (9 MB)
#include <algorithm>

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    std::vector<int> nums3(nums1.begin(), nums1.begin() + m);
    std::merge(nums3.begin(), nums3.end(), nums2.begin(), nums2.end(), nums1.begin());
  }
};
// @lc code=end

