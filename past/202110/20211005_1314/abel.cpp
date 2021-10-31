// Date: Mon Oct 11 17:38:46 2021

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

const int N = 110;
int d[N][N];

class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& a, int k) {
    int n = a.size(), m = a[0].size();
    memset(d, 0, sizeof d);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int i1 = i + 1, j1 = j + 1;
        d[i1][j1] = a[i][j];
        if (i) d[i1][j1] += d[i1 - 1][j1];
        if (j) d[i1][j1] += d[i1][j1 - 1];
        if (i && j) d[i1][j1] -= d[i1 - 1][j1 - 1];
      }
    }

    vector<VI> r(n, VI(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int i1 = i + 1, j1 = j + 1;
        int x = min(i1 + k, n), y = min(j1 + k, m),
          x1 = max(i1 - k - 1, 0), y1 = max(j1 - k - 1, 0);
        r[i][j] = d[x][y] - d[x][y1] - d[x1][y] + d[x1][y1];
      }
    }

    return r;
  }
};
