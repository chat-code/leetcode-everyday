/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 82.84 % of cpp submissions
// Your memory usage beats 38.87 % of cpp submissions (13.2 MB)

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    const auto nr = matrix.size(), nc = matrix[0].size();
    std::vector<bool> rs(nr, false), cs(nc, false);
    for (int i = 0; i < nr; ++i) {
      for (int j = 0; j < nc; ++j) {
        if (matrix[i][j] == 0) {
          rs[i] = true;
          cs[j] = true;
        }
      }
    }
    for (int i = 0; i < nr; ++i) {
      if (rs[i]) {
        for (int j = 0; j < nc; ++j) {
          matrix[i][j] = 0;
        }
      }
    }

    for (int i = 0; i < nc; ++i) {
      if (cs[i]) {
        for (int j = 0; j < nr; ++j) {
          matrix[j][i] = 0;
        }
      }
    }
  }
};
// @lc code=end

// 简评：
// 写的 O(n+m)，constant complexity 没想出来
