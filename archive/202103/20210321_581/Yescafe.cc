/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

#include <vector>
using std::vector;
#include <iostream>

// @lc code=start
// Your runtime beats 86.8 % of cpp submissions
// Your memory usage beats 96.53 % of cpp submissions (26.4 MB)

#include <algorithm>

class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    if (nums.size() <= 1) return 0;   // specified
    int left = 0, right = nums.size() - 1;
    while (left + 1 < nums.size() && nums[left] <= nums[left + 1]) {
      ++left;
    }
    while (right - 1 >= 0 && nums[right - 1] <= nums[right]) {
      --right;
    }

    // std::cout << "L25 here, left = " << left << ", right = " << right << std::endl;
    if (right - left + 1 < 0)   // completely ascending
      return 0;

    auto mme = std::minmax_element(nums.begin() + left, nums.begin() + right + 1);
    auto mi = *mme.first, ma = *mme.second;

    while (left - 1 >= 0 && nums[left - 1] > mi) {
      // std::cout << "L30 --left;" << std::endl;
      --left;
    }
    while (right + 1 < nums.size() && nums[right + 1] < ma) {
      // std::cout << "L34 ++right;" << std::endl;
      ++right;
    }

    int dist;
    if ((dist = right - left + 1) < 1)
      return 0; 
    return dist;
  }
};
// @lc code=end
// testcase: [1,2,4,3,7,5,6,8]

int main()
{
  std::vector<int> ivec {1, 2, 3, 4};
  std::cout << Solution().findUnsortedSubarray(ivec) << std::endl;
  return 0;
}
