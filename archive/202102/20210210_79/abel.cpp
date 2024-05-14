const int N = 210;

int vis[N][N], n, m;
int dir[4][2] = {
  {1, 0}, {-1, 0},
  {0, 1}, {0, -1},
};

class Solution {
public:
  string b;
  vector<vector<char>> a;

  bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  bool dfs(int x, int y, int k) {
    if (a[x][y] != b[k]) return false;
    if (k == b.size() - 1) return true;

    vis[x][y] = 1;

    for (int i = 0; i < 4; ++i) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1) && !vis[x1][y1]) {
        if (dfs(x1, y1, k + 1)) return true;
      }
    }

    vis[x][y] = 0;
    return false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    memset(vis, 0, sizeof vis);
    b = word, a = board;
    n = board.size(), m = board[0].size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (dfs(i, j, 0)) return true;
      }
    }

    return false;
  }
};
