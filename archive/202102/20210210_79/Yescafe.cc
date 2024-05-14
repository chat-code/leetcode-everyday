/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

#include <vector>
#include <string>
using std::vector;
using std::string;

// @lc code=start
// Your runtime beats 32.19 % of cpp submissions
// Your memory usage beats 49.56 % of cpp submissions (30.4 MB)

#include <deque>
#include <utility>

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int r = 0; r < board.size(); ++r) {
      for (int c = 0; c < board[0].size(); ++c) {
        if (board[r][c] == word.front()) {
          if (word.length() == 1) return true;
          std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
          visited[r][c] = true;
          if (dfs(board, word, visited, r, c, 1))
            return true;
        }
      }
    }
    return false;
  }

private:
  bool dfs(vector<vector<char>>& board, string& word, std::vector<std::vector<bool>>& visited, int r, int c, int idx) {
    if (idx == word.length()) return true;
    bool ret = false;
    for (int d = 0; d < 4; ++d) {
      auto nr = r + Dir[d][0];
      auto nc = c + Dir[d][1];
      if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && \
          !visited[nr][nc] && board[nr][nc] == word[idx]) {
        visited[nr][nc] = true;
        ret |= dfs(board, word, visited, nr, nc, idx + 1);
        if (ret) break;
        visited[nr][nc] = false;
      }
    }
    return ret;
  }

private:
  static constexpr int Dir[][2] = {1, 0, -1, 0, 0, 1, 0, -1};
};
// @lc code=end

