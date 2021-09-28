// Date: Sun Sep 26 20:36:59 2021

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
  {-1, 0},
  {0, 1},
  {1, 0},
  {0, -1},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int N = 310, stre[7][4] = {
  {0, 0, 0, 0},
  {0, 1, 0, 1},
  {1, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 1, 1, 0},
  {1, 0, 0, 1},
  {1, 1, 0, 0},
};

bool vis[N][N];
int n, m;

class Solution {
public:
  vector<VI> g;
  void dfs(int x, int y) {
    vis[x][y] = true;

    int x1, y1;
    for (int i = 0; i < 4; ++i) {
      int j = (i + 2) % 4;
      x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (x1 >= 0 && x1 < n &&
          y1 >= 0 && y1 < m && !vis[x1][y1]) {
        if (stre[g[x][y]][i] && stre[g[x1][y1]][j]) {
          dfs(x1, y1);
        }
      }
    }
  }

  bool hasValidPath(vector<vector<int>>& _g) {
    g = _g;
    n = g.size();
    m = g[0].size();
    memset(vis, false, sizeof vis);
    dfs(0, 0);
    return vis[n - 1][m - 1];
  }
};
