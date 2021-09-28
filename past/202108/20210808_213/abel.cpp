// Date: Mon Sep 27 17:38:41 2021

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

const int N = 1010;
int d[N];

class Solution {
public:
  int rob(vector<int>& a) {
    int res = 0;
    int n = a.size();

    memset(d, 0, sizeof d);
    if (n == 1) return a[0];

    res = d[0] = d[1] = a[0];
    for (int i = 2; i <= n - 2; ++i) {
      d[i] = max(d[i - 2] + a[i], d[i - 1]);
      res = max(d[i], res);
    }

    memset(d, 0, sizeof d);
    d[1] = a[1];
    res = max(res, d[1]);
    for (int i = 2; i <= n - 1; ++i) {
      d[i] = max(d[i - 2] + a[i], d[i - 1]);
      res = max(d[i], res);
    }

    return res;
  }
};
