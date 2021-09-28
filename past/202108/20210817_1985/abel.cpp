// Date: Tue Sep  7 15:30:16 2021

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
  string kthLargestNumber(vector<string>& a, int k) {
    sort(a.begin(), a.end(), [&](const string &x, const string &y) {
      int n = x.size(), m = y.size();

      if (n > m) return true;
      else if (n < m) return false;

      for (int i = 0; i < n; ++i) {
        if (x[i] > y[i]) return true;
        else if (x[i] < y[i]) return false;
      }

      return false;
    });

    return a[k - 1];
  }
};
