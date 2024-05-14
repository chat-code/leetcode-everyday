// Date: Sun Oct 31 10:35:11 2021

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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  vector<int> nodesBetweenCriticalPoints(ListNode* he) {
    VI a;
    LNP t = he;
    while (t) {
      a.push_back(t->val);
      t = t->next;
    }
    VI res(2, -1);
    int n = a.size();
    vector<bool> po(n, false);
    int cnt {};
    for (int i = 1; i < n - 1; ++i) {
      if ((a[i] > a[i - 1] && a[i] > a[i + 1]) ||
          (a[i] < a[i - 1] && a[i] < a[i + 1])) {
        po[i] = true;
        cnt++;
      }
    }

    if (cnt < 2) return res;
    res[0] = INF;
    int pre = -1;
    for (int i = 1; i < n - 1; ++i) {
      if (po[i]) {
        if (pre != -1) {
          int tmp = i - pre;
          res[0] = min(res[0], tmp);
          pre = i;
        } else {
          pre = i;
        }
      }
    }

    int x = -1, y = -1;
    for (int i = 1; i < n - 1; ++i) {
      if (po[i]) {
        x = i; break;
      }
    }
    for (int i = n - 2; i >= 1; --i) {
      if (po[i]) {
        y = i; break;
      }
    }

    res[1] = y - x;

    return res;
  }
};
