// Date: Sat Sep 18 20:49:20 2021

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

const int N = 510;
int d[N][N];

class Solution {
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
      int n = a.size(), m = b.size();
      memset(d, 0, sizeof d);
      for (int i = 0; i < n; ++i) {
	for (int j = 0; j < m; ++j) {
	  if (a[i] == b[j]) {
	    if (i == 0 || j == 0) {
	      d[i][j] = 1;
	    } else {
	      d[i][j] = d[i - 1][j - 1] + 1;
	    }
	  } else {
	    if (i && j) {
	      d[i][j] = max(d[i][j - 1], d[i - 1][j]);
	    } else if (i) {
	      d[i][j] = d[i - 1][j];
	    } else if (j) {
	      d[i][j] = d[i][j - 1];
	    }
	  }
	}
      }
      return d[n - 1][m - 1];
    }
};
