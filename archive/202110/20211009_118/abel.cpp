// Date: Sat Oct  9 10:51:24 2021

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

const int N = 50;
int a[N][N];

class Solution {
public:
  vector<vector<int>> generate(int n) {
    for (int i = 0; i < n; ++i) a[i][0] = a[i][i] = 1;
    for (int i = 2; i < n; ++i) {
      for (int j = 1; j < i; ++j)
        a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
    }

    vector<VI> res;
    for (int i = 0; i < n; ++i) {
      VI tmp;
      for (int j = 0; j <= i; ++j) tmp.push_back(a[i][j]);
      res.push_back(tmp);
    }
    return res;
  }
};
