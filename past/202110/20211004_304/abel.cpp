// Date: Mon Oct 11 18:12:49 2021

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

class NumMatrix {
public:
  vector<VI> a, d;
  int n, m;

  NumMatrix(vector<vector<int>>& _m) {
    a = _m;
    n = a.size();
    m = a[0].size();
    d = vector<VI>(n + 1, VI(m + 1, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int i1 = i + 1, j1 = j + 1;
        d[i1][j1] = a[i][j] + d[i1 - 1][j1] + d[i1][j1 - 1] - d[i1 - 1][j1 - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int x1 = row2 + 1, y1 = col2 + 1, x = row1, y = col1;
    return d[x1][y1] - d[x1][y] - d[x][y1] + d[x][y];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
