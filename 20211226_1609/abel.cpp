// Date: Sun Dec 26 23:00:21 2021

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
  using PTI = pair<TNP, int>;

  bool check(VI &v, int level) {
    if (level & 1) {
      if (v[0] & 1) return false;

      for (int i = 1; i < v.size(); ++i) {
        if (v[i] & 1) return false;
        if (v[i] >= v[i - 1]) return false;
      }
    } else {
      if (v[0] % 2 == 0) return false;
      for (int i = 1; i < v.size(); ++i) {
        if (v[i] % 2 == 0 || v[i] <= v[i - 1]) return false;
      }
    }

    return true;
  }

  bool isEvenOddTree(TreeNode* ro) {
    if (!ro) return true;

    int cur = 0;

    VI tmp;
    queue<PTI> q;
    q.push({ro, 0});

    while (!q.empty()) {
      auto t = q.front();
      q.pop();

      int level = t.second;
      auto node = t.first;

      if (level != cur) {
        if (!check(tmp, cur)) return false;

        cur = level;
        tmp.clear();
        tmp.push_back(node->val);
      } else {
        tmp.push_back(node->val);
      }

      auto l = node->left, r = node->right;
      if (l) q.push({l, level + 1});
      if (r) q.push({r, level + 1});
    }

    if (!tmp.empty()) {
      if (!check(tmp, cur)) return false;
    }

    return true;
  }
};
