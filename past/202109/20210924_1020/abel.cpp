// Date: Sun Sep 26 21:00:07 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int N = 510;
bool vis[N][N];
int n, m;

class Solution {
public:
  vector<VI> g;

  void dfs(int x, int y) {
    int x1, y1;
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
      x1 = dir[i][0] + x, y1 = dir[i][1] + y;
      if (x1 >= 0 && x1 < n &&
          y1 >= 0 && y1 < m && !vis[x1][y1] && g[x1][y1]) {
        dfs(x1, y1);
      }
    }
  }

  int numEnclaves(vector<vector<int>>& _g) {
    memset(vis, false, sizeof vis);
    g = _g;
    n = g.size(), m = g[0].size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
          if (g[i][j] && !vis[i][j]) dfs(i, j);
        }
      }
    }

    int res {};
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (g[i][j] && !vis[i][j]) res++;
    return res;
  }
};
