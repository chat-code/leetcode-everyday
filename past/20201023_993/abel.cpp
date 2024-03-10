// Date: Thu Nov 11 17:26:24 2021

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int d1, d2;
  bool flag;
  int x, y;

  void dfs(TNP ro, int cur) {
    if (!ro) return;

    if (ro->val == x) d1 = cur;
    if (ro->val == y) d2 = cur;

    auto l = ro->left, r = ro->right;

    if (l && r) {
      if ((l->val == y && r->val == x) || (l->val == x && r->val == y)) {
        flag = true;
        return;
      }
    }

    if (d1 != -1 && d2 != -1) return;

    if (l) dfs(l, cur + 1);
    if (r) dfs(r, cur + 1);
  }

  bool isCousins(TreeNode* ro, int _x, int _y) {
    x = _x;
    y = _y;
    flag = false;
    d1 = d2 = -1;

    dfs(ro, 0);

    if (flag) return false;
    return d1 == d2;
  }
};
