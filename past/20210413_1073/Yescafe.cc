/*
 * @lc app=leetcode id=1073 lang=cpp
 *
 * [1073] Adding Two Negabinary Numbers
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 19.27 % of cpp submissions
// Your memory usage beats 93.58 % of cpp submissions (19.3 MB)
#include <algorithm>

class Solution {
public:
  vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    std::vector<int> res;
    int carry = 0, i1 = arr1.size() - 1, i2 = arr2.size() - 1;
    while (i1 >= 0 || i2 >= 0 || carry) {
      if (i1 >= 0)
        carry += arr1[i1--];
      if (i2 >= 0)
        carry += arr2[i2--];
      res.push_back(carry & 1);
      carry = -(carry >> 1);
    }

    while (res.size() > 1 && res.back() == 0)
      res.pop_back();
    std::reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end

// testcase
// [1, 1, 1, 1, 1] = 16 - 8 + 4 - 2 + 1 = 11
// [1, 0, 1] = 4 + 1 = 5
