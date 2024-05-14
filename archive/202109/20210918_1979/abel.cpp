// Date: Sat Sep 18 21:00:14 2021

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

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

class Solution {
public:
    int findGCD(vector<int>& a) {
      int x = a[0], y = a[0];
      for (auto &i : a) {
	if (i > x) x = i;
	if (i < y) y = i;
      }
      return gcd(x, y);
    }
};
