/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 94.97 % of cpp submissions (7 MB)

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    auto s = matrix.size();
    for (int i = 0; i < (s + 1) / 2; ++i) {
      for (int j = 0; j < s / 2; ++j) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[s - 1 - j][i];
        matrix[s - 1 - j][i] = matrix[s - 1 - i][s - 1 - j];
        matrix[s - 1 - i][s - 1 - j] = matrix[j][s - 1 - i];
        matrix[j][s - 1 - i] = tmp;
      }
    }
  }
};
// @lc code=end

