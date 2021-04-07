/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 93.92 % of cpp submissions
// Your memory usage beats 14.62 % of cpp submissions (55.5 MB)
#include <numeric>

class Solution {
public:
  int longestOnes(vector<int>& a, int k) {
    int left, right;
    int len = 0;
    left = right = 0;
    int zero_count = 0;
    int ma = std::numeric_limits<int>::min();
    while (right != a.size()) {
      if (a[right] == 1) {
        ++right;
        ++len;
      } else if (zero_count < k) {
        ++right;
        ++len;
        ++zero_count;
      } else {
        if (left == right) right = ++left;
        while (left != right) {
          if (a[left] == 0) {
            ++left;
            --len;
            --zero_count;
            break;
          }
          ++left;
          --len;
        }
      }
      ma = std::max(ma, len);
      while (right < left) ++right;
    }
    return ma;
  }
};
// @lc code=end

// 评价：
// 搞不懂 O(1) 的空间复杂度为什么耗了这么多内存