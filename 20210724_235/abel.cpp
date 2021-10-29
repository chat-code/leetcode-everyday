// Date: Fri Oct 29 19:21:35 2021

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  bool found;

  void fpa(TNP ro, TNP c, vector<TNP> &pa) {
    if (!ro) return;

    if (ro == c) {
      found = true;
      pa.push_back(c);
      return;
    }

    if (!found) fpa(ro->left, c, pa);
    if (!found) fpa(ro->right, c, pa);

    if (found) pa.push_back(ro);
  }

  TreeNode* lowestCommonAncestor(TreeNode* ro, TreeNode* p, TreeNode* q) {
    found = false;
    vector<TNP> pa1;
    fpa(ro, p, pa1);

    found = false;
    vector<TNP> pa2;
    fpa(ro, q, pa2);

    reverse(pa1.begin(), pa1.end());
    reverse(pa2.begin(), pa2.end());

    TNP res;
    int n = pa1.size(), m = pa2.size();
    for (int i = 0, j = 0; i < n && j < m; ++i, ++j) {
      if (pa1[i] == pa2[j]) res = pa1[i];
      else break;
    }

    return res;
  }
};
