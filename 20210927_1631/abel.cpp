// Date: Mon Sep 27 10:30:10 2021

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
int n, m;

class Solution {
public:
  vector<VI> a;

  int spfa() {
    map<PII, int> dis;
    set<PII> st;
    queue<PII> que;

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) dis[PII(i, j)] = INF;

    PII t = PII(0, 0);
    dis[t] = 0;
    st.insert(t);
    que.push(t);

    while (!que.empty()) {
      t = que.front(); que.pop();
      st.erase(t);
      int x = t.first, y = t.second, x1, y1;
      PII t1;

      for (int i = 0; i < 4; ++i) {
        x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (x1 >= 0 && x1 < n &&
            y1 >= 0 && y1 < m) {
          t1 = PII(x1, y1);
          int d = abs(a[x1][y1] - a[x][y]), base = dis[t], tmp = max(d, base);
          if (tmp < dis[t1]) {
            dis[t1] = tmp;
            if (st.find(t1) == st.end()) {
              st.insert(t1);
              que.push(t1);
            }
          }
        }
      }
    }

    return dis[PII(n - 1, m - 1)];
  }

  int minimumEffortPath(vector<vector<int>>& _a) {
    a = _a;
    n = a.size(), m = a[0].size();
    return spfa();
  }
};
