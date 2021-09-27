// Date: Mon Sep 27 15:30:15 2021

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
ll a[N];

class Solution {
public:
  int minCostClimbingStairs(vector<int>& b) {
    memset(a, 0, sizeof a);
    int n = b.size();
    a[0] = b[0], a[1] = b[1];
    for (int i = 2; i < n; ++i) {
      a[i] = b[i] + min(a[i - 1], a[i - 2]);
    }
    a[n] = min(a[n - 1], a[n - 2]);
    return a[n];
  }
};
