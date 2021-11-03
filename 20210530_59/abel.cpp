// Date: Wed Nov  3 22:48:33 2021

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
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

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

class Solution {
public:
  vector<VI> res;
  int cur, n;

  bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
  }

  void dfs(int x, int y, int idx) {
    int x1, y1;

    res[x][y] = cur;

    if (cur == n * n) return;
    cur++;

    x1 = x + dir[idx][0], y1 = y + dir[idx][1];
    while (!check(x1, y1) || res[x1][y1]) {
      idx = (idx + 1) % 4;
      x1 = x + dir[idx][0], y1 = y + dir[idx][1];
    }

    dfs(x1, y1, idx);
  }

  vector<vector<int>> generateMatrix(int _n) {
    n = _n;
    res = vector<VI>(n, VI(n, 0));
    cur = 1;

    dfs(0, 0, 0);

    return res;
  }
};
