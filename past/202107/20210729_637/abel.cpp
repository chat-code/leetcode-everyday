// Date: Fri Oct 29 09:17:57 2021

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
  using PTI = pair<TNP, int>;

  vector<double> averageOfLevels(TreeNode* ro) {
    vector<double> res;
    if (!ro) return res;

    int cur = 1;
    queue<PTI> que;
    que.push(PTI(ro, 1));
    VI tmp;

    while (!que.empty()) {
      auto t = que.front(); que.pop();
      auto node = t.first;
      int level = t.second;

      if (cur != level) {
        double sum = 0;
        for (auto &i : tmp) sum += i;
        res.push_back(sum / tmp.size());
        cur = level;
        tmp.clear();
        tmp.push_back(node->val);
      } else {
        tmp.push_back(node->val);
      }

      if (node->left) que.push(PTI(node->left, level + 1));
      if (node->right) que.push(PTI(node->right, level + 1));
    }

    if (!tmp.empty()) {
      double sum = 0;
      for (auto &i : tmp) sum += i;
      res.push_back(sum / tmp.size());
    }

    return res;
  }
};
