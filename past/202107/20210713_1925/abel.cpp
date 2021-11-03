// Date: Sun Jul 11 00:19:11 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int dir[8][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef vector<int> VI;


class Solution {
public:
  int countTriples(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= n; ++k) {
          if (i * i + j * j == k * k) {
            ++res;
          }
        }
      }
    }

    return res;
  }
};
