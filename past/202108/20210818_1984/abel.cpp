// Date: Tue Sep  7 15:19:10 2021

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
  int minimumDifference(vector<int>& a, int k) {
    sort(a.begin(), a.end());
    int n = a.size();
    int res = a[k - 1] - a[0];
    for (int i = 0; i <= n - k; ++i) {
      res = min(res, a[i + k - 1] - a[i]);
    }
    return res;
  }
};
