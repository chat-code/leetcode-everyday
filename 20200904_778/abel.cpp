const int N = 55;
int vis[N][N], a[N][N], n, m;
int dir[4][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
};

class Solution {
public:
  bool dfs(int x, int y) {
    if (x == n && y == n) return true;

    vis[x][y] = 1;

    bool flag = false;

    for (int i = 0; i < 4; ++i) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];

      if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n) {
        if (!vis[x1][y1] && a[x1][y1] <= m) {
          flag |= dfs(x1, y1);
          if (flag) return true;
        }
      }
    }

    return flag;
  }

  int swimInWater(vector<vector<int>>& grid) {
    n = grid.size();
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        a[i + 1][j + 1] = grid[i][j];

    int l = a[1][1], r = n * n + 1, mid;
    while (l < r) {
      mid = (l + r) >> 1;

      m = mid;
      memset(vis, 0, sizeof vis);
      if (dfs(1, 1)) r = mid;
      else l = mid + 1;
    }

    return r;
  }
};
