/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 9.64 % of cpp submissions
// Your memory usage beats 78.5 % of cpp submissions (18.3 MB)

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    X = matrix.size();
    Y = matrix[0].size();
    std::vector<int> link;
    int rng = X + Y - 1;
    for (int sum = 0; sum < rng; ++sum) { 
      if (sum & 1) {  // odd
        for (int x = 0; x <= sum; ++x) {
          int y = sum - x;
          if (checkIdx(x, y))
            link.push_back(matrix[x][y]);
        }
      } else {        // even
        for (int y = 0; y <= sum; ++y) {
          int x = sum - y;
          if (checkIdx(x, y))
            link.push_back(matrix[x][y]);
        }
      }
    }
    return link;
  }

private:
  bool checkIdx(int x, int y) {
    return x >= 0 && x < X && \
      y >= 0 && y < Y;
  }
  int X, Y;
};
// @lc code=end

// 评价：
// 代码逻辑比上一次写的简单，但是不知道为什么时间还是这么慢。加了 todo，改天找个人讨论一下。
