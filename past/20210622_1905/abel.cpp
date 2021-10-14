int dir[4][2] = {
  {1, 0}, {-1, 0},
  {0, 1}, {0, -1},
};
const int N = 510;
int vis[N][N], a[N][N];
int n, m;

class Solution {
public:
  bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  void dfs(int x, int y, bool &f) {
    vis[x][y] = 1;

    for (int i = 0; i < 4; ++i) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1) && !vis[x1][y1]) {
        if (a[x1][y1] == 2) {
          f = true;
          dfs(x1, y1, f);
        } else if (a[x1][y1] == 3) {
          dfs(x1, y1, f);
        }
      }
    }
  }

  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    memset(vis, 0, sizeof vis);

    n = grid1.size();
    m = grid1[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        a[i][j] = grid1[i][j];
        if (grid2[i][j]) {
          a[i][j] |= 2;
        }
      }
    }

    int res {};

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!vis[i][j] && a[i][j] == 3) {
          bool found = false;

          dfs(i, j, found);

          if (!found) {
            res++;
          }
        }
      }
    }

    return res;
  }
};
