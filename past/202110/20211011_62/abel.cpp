// Date: Mon Oct 11 17:10:24 2021

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
  int uniquePaths(int m, int n) {
    memset(d, 0, sizeof d);
    for (int i = 0; i < m; ++i) d[i][0] = 1;
    for (int j = 0; j < n; ++j) d[0][j] = 1;

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        d[i][j] = d[i - 1][j] + d[i][j - 1];
      }
    }

    return d[m - 1][n - 1];
  }
};
