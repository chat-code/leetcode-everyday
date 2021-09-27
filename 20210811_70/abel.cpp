// Date: Mon Sep 27 15:21:28 2021

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

const int N = 100;
ll a[N];

class Solution {
public:
  int climbStairs(int n) {
    memset(a, 0, sizeof a);
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; ++i) {
      a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
  }
};
