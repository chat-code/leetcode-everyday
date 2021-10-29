// Date: Thu Sep 23 16:00:49 2021

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

const int N = 50;
int cnt, primes[N];
bool st[N];

void get_primes_v2(int n) {
  cnt = 0;
  st[0] = st[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) primes[cnt++] = i;
    for (int j = 0; primes[j] <= n / i; ++j) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) break;
    }
  }
}

class Solution {
public:
  int countPrimeSetBits(int a, int b) {
    int res = 0;
    cnt = 0;
    memset(st, false, sizeof st);
    get_primes_v2(40);

    for (int i = a; i <= b; ++i) {
      int cnt = 0;
      int n = i;
      while (n) {
        cnt++;
        n-= (n & (-n));
      }
      if (!st[cnt]) res++;
    }

    return res;
  }
};
