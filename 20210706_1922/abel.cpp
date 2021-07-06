// Date: Tue Jul  6 16:26:51 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int dir[8][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};
typedef long long ll;

ll qmi(ll a, ll b, ll c) {
  ll res = 1 % c;
  while (b) {
    if (b & 1) res = res * a % c;
    a = a * a % c;
    b >>= 1;
  }
  return res;
}

class Solution {
public:
    int countGoodNumbers(long long n) {
      return qmi(5, (n + 1) / 2, MOD) * qmi(4, n / 2, MOD) % MOD;
    }
};
