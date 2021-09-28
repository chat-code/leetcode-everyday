// Date: Tue Sep 28 10:46:39 2021

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
int d[N];

class Solution {
public:
  int maxSubarraySumCircular(vector<int>& a) {
    int res = a[0];
    int n = a.size();

    memset(d, 0, sizeof d);
    d[0] = a[0];
    for (int i = 1; i < n; ++i) {
      d[i] = max(d[i - 1] + a[i], a[i]);
    }
    for (int i = 0; i < n; ++i) res = max(res, d[i]);

    int tmp = a[0];
    memset(d, 0, sizeof d);
    d[0] = a[0];
    for (int i = 1; i < n; ++i) {
      d[i] = min(a[i], d[i - 1] + a[i]);
    }
    for (int i = 0; i < n; ++i) tmp = min(tmp, d[i]);

    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];

    if (tmp != sum)
      res = max(res, sum - tmp);

    return res;
  }
};
