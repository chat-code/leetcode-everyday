// Date: Wed Oct 27 14:29:17 2021

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

const int N = 610, M = 110;
int d[M][M];
int on[N], tw[N];

class Solution {
public:
  int findMaxForm(vector<string>& a, int m, int n) {
    int n1 = a.size();
    memset(d, 0, sizeof d);
    memset(on, 0, sizeof on);
    memset(tw, 0, sizeof tw);

    for (int i = 0; i < n1; ++i) {
      int one = 0, two {};
      for (auto &c : a[i]) {
        if (c == '1') one++;
        else two++;
      }
      on[i] = one;
      tw[i] = two;
    }

    for (int i = 0; i < n1; ++i) {
      for (int v = n; v >= on[i]; --v) {
        for (int z = m; z >= tw[i]; --z) {
          d[v][z] = max(d[v][z], d[v - on[i]][z - tw[i]] + 1);
        }
      }
    }

    return d[n][m];
  }
};
