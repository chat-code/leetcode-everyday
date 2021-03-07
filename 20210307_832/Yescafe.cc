/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
// Your runtime beats 92.66 % of cpp submissions
// Your memory usage beats 84.83 % of cpp submissions (8.7 MB)

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    for (auto& row : image) {
      for (int i = 0; i < (row.size() + 1) / 2; ++i) {
        row[i] = (row[i] + 1) % 2;
        if (i != row.size() - 1 - i) {
          row[row.size() - 1 - i] = (row[row.size() - 1 - i] + 1) % 2;
          std::swap(row[i], row[row.size() - 1 - i]);
        }
      }
    }
    return image;
  }
};
// @lc code=end
