// Date: Sat Oct  9 17:29:56 2021

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
  bool check(char a, char b) {
    int x = a - '0', y = b - '0';
    int r = x * 10 + y;
    return r >= 10 && r <= 26;
  }
  int numDecodings(string s) {
    int n = s.size();
    VI d(n, 0);
    if (s[0] == '0') return 0;

    d[0] = 1;
    for (int i = 1; i < n; ++i) {
      if (s[i] != '0') {
        d[i] = d[i - 1];
      }
      if (check(s[i - 1], s[i])) {
        if (i >= 2) d[i] += d[i - 2];
        else d[i]++;
      } else {
        if (s[i] == '0') return 0;
      }
    }

    return d[n - 1];
  }
};
