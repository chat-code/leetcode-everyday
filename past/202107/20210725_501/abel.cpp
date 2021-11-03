// Date: Fri Oct 29 18:29:42 2021

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
  int cur, pre, lenx, len;
  VI res;

  void dfs(TNP ro) {
    if (!ro) return;

    dfs(ro->left);

    cur = ro->val;

    if (pre != -INF) {
      if (pre == cur) {
        lenx++;
        if (lenx > len) {
          len = lenx;
          res.clear();
          res.push_back(cur);
        } else if (lenx == len) {
          res.push_back(cur);
        }
      } else {
        lenx = 1;
        pre = cur;

        if (len == lenx) {
          res.push_back(cur);
        }
      }
    } else {
      pre = cur;
      lenx = 1;
      res.push_back(cur);
    }

    dfs(ro->right);
  }

  vector<int> findMode(TreeNode* ro) {
    pre = -INF;
    cur = 0;
    len = 1;
    dfs(ro);
    return res;
  }
};

