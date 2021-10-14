// Date: Thu Oct 14 15:53:44 2021

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

#ifdef _DEBUG

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

typedef ListNode LN;
typedef LN* LNP;

#endif

const int N = 22, M = 1010;
int d[N][M];

class Solution {
public:
  int findTargetSumWays(vector<int>& a, int t) {
    memset(d, 0, sizeof d);
    int n = a.size(), sum = 0;

    for (int i = 0; i < n; ++i) sum += a[i];
    int s1 = sum + t;
    if ((s1 & 1) || s1 < 0) return 0;
    s1 /= 2;

    d[0][a[0]] = d[0][0] = 1;
    if (a[0] == 0) d[0][a[0]] = 2;

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= sum; ++j) {
        if (j >= a[i]) d[i][j] += d[i - 1][j - a[i]];
        d[i][j] += d[i - 1][j];
      }
    }

    return d[n - 1][s1];
  }
};
