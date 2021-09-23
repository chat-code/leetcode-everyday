// Date: Thu Sep 23 16:55:11 2021

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
  int count1(int x) {
    int res {};
    while (x) {
      res++;
      x /= 10;
    }
    return res;
  }
  int findNumbers(vector<int>& a) {
    int res {};
    for (auto c : a) {
      res += (count1(c) % 2 == 0);
    }
    return res;
  }
};
