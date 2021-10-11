// Date: Mon Oct 11 17:15:44 2021

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
  int uniquePathsWithObstacles(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    memset(d, 0, sizeof d);
    if (a[0][0] == 0)
      d[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j]) continue;
        if (i && d[i - 1][j]) d[i][j] += d[i - 1][j];
        if (j && d[i][j - 1]) d[i][j] += d[i][j - 1];
      }
    }

    return d[n - 1][m - 1];
  }
};
