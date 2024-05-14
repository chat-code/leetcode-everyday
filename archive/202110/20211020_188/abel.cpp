// Date: Thu Oct 28 16:36:55 2021

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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif

typedef ListNode LN;
typedef LN* LNP;
typedef TreeNode TN;
typedef TN* TNP;

const int N = 1010, M = 110;
int d[N][2][M];

class Solution {
public:
  int maxProfit(int k, vector<int>& a) {
    memset(d, 0, sizeof d);
    int n = a.size();
    if (!n) return 0;

    for (int j = 1; j <= k; ++j) {
      d[0][1][j] = -INF;
      if (j >= 2) d[0][0][j] = -INF;
    }
    d[0][1][0] = -a[0];

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        int j1 = j + 1;

        d[i][0][j1] = max(d[i - 1][1][j1 - 1] + a[i], d[i - 1][0][j1]);
        d[i][1][j] = max(d[i - 1][0][j] - a[i], d[i - 1][1][j]);
      }
    }

    int res {};
    for (int j = 0; j <= k; ++j) res = max(res, d[n - 1][0][j]);

    return res;
  }
};
