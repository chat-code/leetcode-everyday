// Date: Mon Sep 27 15:05:15 2021

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
ll a[N];

class Solution {
public:
  int tribonacci(int n) {
    memset(a, 0, sizeof a);
    a[0] = 0, a[1] = a[2] = 1;
    for (int i = 3; i <= n; ++i) {
      a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    return a[n];
  }
};
