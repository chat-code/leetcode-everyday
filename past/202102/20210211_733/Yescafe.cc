/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 67.15 % of cpp submissions
// Your memory usage beats 64.92 % of cpp submissions (14.2 MB)

#include <deque>
#include <utility>

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    std::deque<std::pair<int, int>> idq;
    idq.push_back({sr, sc});
    auto oriColor = image[sr][sc];
    image[sr][sc] = newColor;

    while (!idq.empty()) {
      auto& p = idq.front();
      for (int d = 0; d < 4; ++d) {
        auto nr = p.first  + Dir[d][0];
        auto nc = p.second + Dir[d][1];
        if (nr >= 0 && nr < image.size() && nc >= 0 && nc <= image[0].size() && \
            image[nr][nc] == oriColor && image[nr][nc] != newColor) {
          image[nr][nc] = newColor;
          idq.push_back({nr, nc});
        }
      }
      idq.pop_front();
    }

    return image;
  }

private:
  static constexpr int Dir[][2] = {1, 0, -1, 0, 0, 1, 0, -1};
};
// @lc code=end

// 评论：
// 在计算机图形学中有用到 BFS 的算法叫种子填充，这题使用了类似种子填充的技术（因为我不记得种子填充是什么样的了，所以只能写 BFS）。
// 当然 DFS 也可。
