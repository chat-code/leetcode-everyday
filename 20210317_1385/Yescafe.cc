/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 95.92 % of cpp submissions
// Your memory usage beats 95.53 % of cpp submissions (12.9 MB)

#include <cmath>

class Solution {
public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int cnt = 0;
    for (auto&& a : arr1) {
      bool cntd = true;
      for (auto&& b : arr2) {
        if (!cntd) break;
        if (std::abs(a - b) <= d) cntd = false;
      }
      if (cntd) ++cnt;
    }
    return cnt;
  }
};
// @lc code=end

