// Date: Thu Nov  4 10:03:12 2021

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

const int N = 100010;
int d1[N], d2[N], stk[N], tt;

class Solution {
public:
  int largestRectangleArea(vector<int>& a) {
    int n = a.size(), res = 0;

    tt = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (!tt) d1[i] = -1;
      else {
        while (tt && a[i] <= a[stk[tt]]) --tt;
        if (tt) d1[i] = stk[tt];
        else d1[i] = -1;
      }
      stk[++tt] = i;
    }
    tt = 0;
    for (int i = 0; i < n; ++i) {
      if (!tt) d2[i] = -1;
      else {
        while (tt && a[i] <= a[stk[tt]]) --tt;
        if (tt) d2[i] = stk[tt];
        else d2[i] = -1;
      }
      stk[++tt] = i;
    }
    for (int i = 0; i < n; ++i) {
      int l, r;
      if (d2[i] == -1) l = 0;
      else l = d2[i] + 1;
      if (d1[i] == -1) r = n - 1;
      else r = d1[i] - 1;
      res = max(res, (r - l + 1) * a[i]);
    }

    return res;
  }
};
