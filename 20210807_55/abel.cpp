// Date: Mon Sep 27 20:45:02 2021

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

const int N = 30010;
int n;

class Solution {
public:
  bool canJump(vector<int>& a) {
    n = a.size();
    int cur = 0;
    for (int i = 0; i <= cur; ++i) {
      int ne = i + a[i];
      cur = max(cur, ne);
      if (cur >= n - 1) return true;
    }
    return false;
  }
};
