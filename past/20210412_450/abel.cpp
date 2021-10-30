// Date: Fri Oct 29 23:14:16 2021

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
  TNP find_next(TNP ro) {
    auto l = ro->left;
    if (l) return find_next(l);
    return ro;
  }

  TNP find_prev(TNP ro) {
    auto r = ro->right;
    if (r) return find_prev(r);
    return ro;
  }

  bool leaf(TNP ro) { return !ro->left && !ro->right; }

  TreeNode* deleteNode(TreeNode* ro, int key) {
    if (!ro) return ro;

    auto x = ro->val;
    auto l = ro->left, r = ro->right;

    if (x > key) {
      ro->left = deleteNode(l, key);
      return ro;
    } else if (x < key) {
      ro->right = deleteNode(r, key);
      return ro;
    } else {
      if (leaf(ro)) return nullptr;
      if (l) {
        auto pre = find_prev(l);
        ro->val = pre->val;
        ro->left = deleteNode(l, pre->val);
        return ro;
      } else {
        auto ne = find_next(r);
        ro->val = ne->val;
        ro->right = deleteNode(r, ne->val);
        return ro;
      }
    }

    return ro;
  }
};
