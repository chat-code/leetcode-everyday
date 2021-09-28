// Date: Mon Sep  6 20:39:25 2021

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

class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    int n = right - left, cur = 0, x = 1, idx = 0;
    int res = left, remain = 0;

    while (left) {
      if (x > INT_MAX / 2) break;
      x <<= 1;

      if (left & 1) {
        cur = cur + (x >> 1);

        remain = x - cur;
        if (remain <= n) {
          res -= (x >> 1);
        }
      }

      left >>= 1;
    }

    return res;
  }
};
