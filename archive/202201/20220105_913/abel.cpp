// Date: Wed Jan  5 21:42:52 2022

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>

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
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

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

const int N = 55;
int d[N * 2][N][N], n;

class Solution {
public:
  vector<VI> g;

  int dfs(int k, int i, int j) {
    if (d[k][i][j] != -1) return d[k][i][j];

    int &ans = d[k][i][j];

    if (k >= 2 * n) return ans = 0;

    if (k % 2 == 0) {
      int res = -1;

      for (auto &x : g[i]) {
        int tmp = dfs(k + 1, x, j);
        if (tmp == 1) return ans = 1;
        else if (tmp == 0) res = 0;
      }

      if (res == 0) return ans = 0;

      return ans = 2;
    } else {
      int res = -1;

      for (auto &x : g[j]) {
        if (x == 0) continue;
        int tmp = dfs(k + 1, i, x);
        if (tmp == 2) return ans = 2;
        else if (tmp == 0) res = 0;
      }

      if (res == 0) return ans = 0;

      return ans = 1;
    }

    return ans;
  }

  int catMouseGame(vector<vector<int>>& _g) {
    g = _g;
    n = g.size();
    memset(d, -1, sizeof d);

    for (int i = 0; i < 2 * n; ++i)
      for (int j = 0; j < n; ++j)
        d[i][0][j] = 1;

    for (int k = 0; k < 2 * n; ++k)
      for (int i = 1; i < n; ++i)
        d[k][i][i] = 2;

    return dfs(0, 1, 2);
  }
};
