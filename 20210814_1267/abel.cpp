// Date: Sun Sep 26 20:11:10 2021

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

class Solution {
public:
  map<PII, PII> fa;
  map<PII, int> sz;

  PII Find(PII x) {
    if (fa.find(x) == fa.end()) {
      fa[x] = x;
      sz[x] = 1;
      return x;
    }
    if (fa[x] == x) return x;
    return fa[x] = Find(fa[x]);
  }

  void Union(PII x, PII y) {
    PII rx = Find(x), ry = Find(y);
    if (rx == ry) return;
    fa[ry] = rx;
    sz[rx] += sz[ry];
  }

  int countServers(vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size();
    fa.clear(), sz.clear();
    int res {};

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (g[i][j]) {
          Find(PII(i, j));
        }
      }
      bool flag = false;
      PII pre;
      for (int j = 0; j < m; ++j) {
        if (g[i][j]) {
          PII tmp = PII(i, j);
          if (!flag) {
            flag = true;
            pre = tmp;
          } else {
            Union(tmp, pre);
            pre = tmp;
          }
        }
      }
    }
    for (int j = 0; j < m; ++j) {
      bool flag = false;
      PII pre, tmp;

      for (int i = 0; i < n; ++i) {
        if (g[i][j]) {
          tmp = PII(i, j);
          if (!flag) {
            flag = true;
            pre = tmp;
          } else {
            Union(tmp, pre);
            pre = tmp;
          }
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        PII t = PII(i, j), rt = Find(t);
        if (sz[rt] > 1) res++;
      }
    }

    return res;
  }
};
