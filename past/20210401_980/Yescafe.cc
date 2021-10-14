/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

#include <vector>
using std::vector;
#include <iostream>

// @lc code=start
// Runtime: 4 ms, faster than 79.66% of C++ online submissions for Unique Paths III.
// Memory Usage: 7.3 MB, less than 33.85% of C++ online submissions for Unique Paths III.

#include <utility>
constexpr int dirs[][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };

class Solution {
public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    len = ret = path = 0;
    X = grid.size(), Y = grid[0].size();
    std::pair<int, int> start_point, end_point;
    for (int x = 0; x < X; ++x) {
      for (int y = 0; y < Y; ++y) {
        switch(grid[x][y]) {
         case 0:
          ++len;
          break;
         case 1:
          ++len;
          start_point.first = x;
          start_point.second = y;
          break;
         case 2:
          ++len;
          end_point.first = x;
          end_point.second = y;
          break;
        }
      }
    }

    vis.assign(X + 1, std::vector<bool>(Y + 1, false));
    ++path;
    paths.push_back(start_point);
    vis[start_point.first][start_point.second] = true;
    dfs(start_point.first, start_point.second, grid);
    return ret;
  }

private:
  void dfs(int x, int y, std::vector<std::vector<int>>& grid) {
    if (grid[x][y] == 2) {
      if (path == len) {
        ++ret;
        for (auto&& p : paths) {
          std::cout << "(" << p.first << ", " << p.second << ") ";
        }
        std::endl(std::cout);
      }
      return ;
    }
    for (int d = 0; d < 4; ++d) {
      auto nx = x + dirs[d][0];
      auto ny = y + dirs[d][1];
      if (nx >= 0 && nx < X && ny >= 0 && ny < Y && !vis[nx][ny] && grid[nx][ny] != -1) {
        ++path;
        paths.push_back({nx, ny});
        vis[nx][ny] = true;
        dfs(nx, ny, grid);
        vis[nx][ny] = false;
        paths.pop_back();
        --path;
      }
    }
  }

  int X, Y;     // length of x and y
  int ret;      // return number
  int len;      // needs length
  int path;     // traverse length
  std::vector<std::vector<bool>> vis;
  std::vector<std::pair<int, int>> paths;
};
// @lc code=end

