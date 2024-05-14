// Date: Sat Jan 15 09:52:13 2022

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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

const ull Pr = 131;

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
  bool checkValid(vector<vector<int>>& a) {
    int n = a.size();
    int vis[110];

    for (int i = 0; i < n; ++i) {
      memset(vis, 0, sizeof vis);
      for (int j = 0; j < n; ++j) vis[a[i][j]] = 1;

      int cnt {};
      for (int j = 1; j <= n; ++j) cnt += vis[j];

      if (cnt != n) return false;
    }

    for (int i = 0; i < n; ++i) {
      memset(vis, 0, sizeof vis);
      for (int j = 0; j < n; ++j) vis[a[j][i]] = 1;

      int cnt {};
      for (int j = 1; j <= n; ++j) cnt += vis[j];

      if (cnt != n) return false;
    }

    return true;
  }
};
