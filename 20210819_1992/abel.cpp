// Date: Tue Sep  7 14:46:31 2021

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

const int N = 310;
bool vis[N][N];

class Solution {
public:
  vector<VI> res;
  vector<PII> cur;
  vector<VI> a;
  int m, n;

  void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && !vis[x1][y1] && a[x1][y1] == 1) {
        cur.push_back(PII(x1, y1));
        dfs(x1, y1);
      }
    }
  }

  vector<vector<int>> findFarmland(vector<vector<int>>& g) {
    a = g;
    memset(vis, false, sizeof vis);
    m = a.size(); n = a[0].size();
    cur = vector<PII>{};
    res = vector<VI>{};

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!vis[i][j] && a[i][j] == 1) {
          cur.push_back(PII(i, j));
          dfs(i, j);
          sort(cur.begin(), cur.end());
          if (cur.empty()) continue;

          auto x = cur[0], y = cur[cur.size() - 1];
          res.push_back(VI{x.first, x.second, y.first, y.second});
          cur = vector<PII>{};
        }
      }
    }

    return res;
  }
};
