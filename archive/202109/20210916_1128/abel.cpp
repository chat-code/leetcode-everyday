// Date: Sat Sep 18 20:56:01 2021

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
  int numEquivDominoPairs(vector<vector<int>>& a) {
    map<PII, int> m;
    for (auto &x : a) {
      PII p;
      if (x[0] <= x[1]) {
	p.first = x[0], p.second = x[1];
      } else {
	p.first = x[1], p.second = x[0];
      }
      m[p]++;
    }
    int res = 0;
    for (auto &x : m) {
      int y = x.second;
      if (y > 1) {
	res += y * (y - 1) / 2;
      }
    }
    return res;
  }
};
