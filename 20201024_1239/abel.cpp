// Date: Thu Nov 11 17:15:04 2021

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

bool vis[30];

class Solution {
public:
  vector<string> a;
  int n, res;

  bool check(string &s) {
    bool st[30] {};
    for (auto &c : s) {
      if (st[c - 'a']) return false;
      st[c - 'a'] = true;
    }

    for (auto &c : s) {
      if (vis[c - 'a']) return false;
    }
    return true;
  }
  void adds(string &s) {
    for (auto &c : s) vis[c - 'a'] = true;
  }
  void removes(string &s) {
    for (auto &c : s) vis[c - 'a'] = false;
  }

  void dfs(int idx, string cur) {
    if (idx >= n) {
      res = max(res, int(cur.size()));
      return;
    }

    dfs(idx + 1, cur);
    if (check(a[idx])) {
      adds(a[idx]);
      dfs(idx + 1, cur + a[idx]);
      removes(a[idx]);
    }
  }

  int maxLength(vector<string>& _a) {
    a = _a;
    n = a.size();
    res = 0;
    memset(vis, false, sizeof vis);

    dfs(0, "");

    return res;
  }
};
