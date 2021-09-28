// Date: Tue Sep 28 11:45:37 2021

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

const int N = 100010;
int d1[N], d2[N];

class Solution {
public:
  int getMaxLen(vector<int>& a) {
    int n = a.size();
    int res = 0;

    memset(d1, 0, sizeof d1);
    memset(d2, 0, sizeof d2);

    if (a[0] > 0) d1[0] = 1;
    else if (a[0] < 0) d2[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (a[i] > 0) {
        d1[i] = d1[i - 1] + 1;
        if (d2[i - 1] > 0) {
          d2[i] = d2[i - 1] + 1;
        } else {
          d2[i] = 0;
        }
      } else if (a[i] < 0) {
        if (d2[i - 1] > 0) {
          d1[i] = d2[i - 1] + 1;
        } else d1[i] = 0;

        if (d1[i - 1] > 0) {
          d2[i] = d1[i - 1] + 1;
        } else d2[i] = 1;
      } else {
        d1[i] = d2[i] = 0;
      }
    }

    for (int i = 0; i < n; ++i) {
      res = max(res, d1[i]);
    }

    return res;
  }
};
