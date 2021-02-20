#include <vector>
#include <cstring>

using namespace std;

const int N = 55;
int vis[N][N];
int dir[4][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
};

class Solution {
public:
  int c, nc, n, m;
  vector<vector<int>> a;

  bool check(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
  }

  void dfs(int x, int y) {
    vis[x][y] = 1;
    a[x][y] = nc;

    int x1, y1;
    for (int i = 0; i < 4; ++i) {
      x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1)) {
        if (!vis[x1][y1] && a[x1][y1] == c) {
          dfs(x1, y1);
        }
      }
    }
  }

  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    memset(vis, 0, sizeof vis);
    n = image.size(), m = image[0].size();
    c = image[sr][sc], nc = newColor;
    a = image;
    dfs(sr, sc);
    return a;
  }
};
