// Date: Sat Oct  9 11:21:19 2021

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
  int minFallingPathSum(vector<vector<int>>& a) {
    memset(d, 0x3f, sizeof d);
    int n = a.size();
    int res = INF;

    for (int i = 0; i < n; ++i) d[0][i] = a[0][i];
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int tmp = d[i - 1][j];
        if (j > 0) tmp = min(tmp, d[i - 1][j - 1]);
        if (j < n - 1) tmp = min(tmp, d[i - 1][j + 1]);
        d[i][j] = tmp + a[i][j];
      }
    }
    for (int j = 0; j < n; ++j) res = min(res, d[n - 1][j]);

    return res;
  }
};
