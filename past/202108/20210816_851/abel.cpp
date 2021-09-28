// Date: Thu Sep  9 17:14:57 2021

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

const int N = 510, M = 260000;
int n, m, h[N], res[N];
bool st[N];
int idx, e[M], ne[M];

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(st, false, sizeof st);
  memset(res, 0x3f, sizeof res);
}

void Add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
  VI quiet;
  void dfs(int x, int &cur) {
    st[x] = true;
    for (int j = h[x]; j != -1; j = ne[j]) {
      int y = e[j];
      if (st[y]) {
        if (quiet[res[y]] <= quiet[cur]) cur = res[y];
      } else {
        int cury = y;
        dfs(y, cury);
        res[y] = cury;
        if (quiet[cury] <= quiet[cur]) cur = res[y];
      }
    }
    res[x] = cur;
  }

  vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet1) {
    quiet = quiet1;
    Init();
    n = quiet.size(), m = richer.size();

    for (auto &r : richer) {
      Add(r[1], r[0]);
    }

    for (int i = 0; i < n; ++i) {
      if (!st[i]) {
        int cur = i;
        dfs(i, cur);
      }
    }

    VI res1;
    for (int i = 0; i < n; ++i) res1.push_back(res[i]);
    return res1;
  }
};
