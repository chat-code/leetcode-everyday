// Date: Thu Sep 23 17:01:24 2021

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
  int minOperations(vector<int>& a) {
    int res {}, n = a.size(), pre = a[0];
    for (int i = 1; i < n; ++i) {
      if (a[i] > pre) {
        pre = a[i];
        continue;
      }

      res += (pre + 1 - a[i]);
      pre++;
    }
    return res;
  }
};
