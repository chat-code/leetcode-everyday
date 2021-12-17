// Date: Fri Dec 17 20:37:30 2021

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

class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& a) {
    int n = a.size();
    VI r(n, 0), c(n, 0);

    for (int i = 0; i < n; ++i) {
      int cur = -1;
      for (int j = 0; j < n; ++j) {
        cur = max(cur, a[i][j]);
      }
      r[i] = cur;
    }

    for (int j = 0; j < n; ++j) {
      int cur = -1;
      for (int i = 0; i < n; ++i) {
        cur = max(cur, a[i][j]);
      }
      c[j] = cur;
    }

    int res {};

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        res += min(r[i], c[j]) - a[i][j];
      }
    }

    return res;
  }
};
