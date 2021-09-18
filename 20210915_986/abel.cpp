// Date: Sat Sep 18 20:13:12 2021

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
  VI inter(VI& x, VI& y) {
    if (not_inter(x, y)) return VI();
    if (x[0] > y[0]) return inter(y, x);
    return VI{y[0], min(x[1], y[1])};
  }
  bool not_inter(VI &x, VI &y) {
    if (x[0] > y[1] || y[0] > x[1]) return true;
    return false;
  }
  
  vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<VI> res;
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    VI cur;

    while (i < n && j < m) {
      if (not_inter(a[i], b[j])) {
	if (a[i][0] > b[j][1]) ++j;
	else ++i;
	continue;
      }
      auto tmp = inter(a[i], b[j]);
      res.push_back(tmp);
      if (a[i][1] >= b[j][1]) {
	++j;
	a[i][0] = tmp[1] + 1;
      } else {
	++i;
	b[j][0] = tmp[1] + 1;
      }
    }
    return res;
  }
};
