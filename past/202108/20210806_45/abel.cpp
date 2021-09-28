// Date: Mon Sep 27 20:57:24 2021

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

const int N = 10010;
int d[N], n;

class Solution {
public:
  int jump(vector<int>& a) {
    n = a.size();
    memset(d, INF, sizeof d);
    d[0] = 0;
    int cur = 0;
    for (int i = 0; i <= cur && i < n; ++i) {
      int ne = i + a[i];
      if (ne > cur) {
        for (int j = cur + 1; j <= ne && j < n; ++j) {
          d[j] = d[i] + 1;
        }
        cur = ne;
      }
    }
    return d[n - 1];
  }
};
