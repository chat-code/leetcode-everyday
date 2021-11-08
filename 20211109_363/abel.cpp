// Date: Mon Nov  8 23:35:14 2021

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
  int maxSumSubmatrix(vector<vector<int>>& a, int K) {
    int n = a.size(), m = a[0].size();
    vector<VI> p(n + 1, VI(m + 1, 0));

    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        p[i + 1][j] = p[i][j] + a[i][j];
      }
    }

    int res = -INF;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        VI b(m, 0), p1(m + 1, 0);
        for (int k = 0; k < m; ++k) b[k] = p[j + 1][k] - p[i][k];
        for (int k = 0; k < m; ++k) p1[k + 1] = p1[k] + b[k];

        set<int> s;
        s.insert(0);
        for (int k = 1; k <= m; ++k) {
          int tmp = p1[k] - K;
          auto it = s.lower_bound(tmp);
          if (it != s.end())
            res = max(res, p1[k] - *it);
          s.insert(p1[k]);
        }
      }
    }

    return res;
  }
};
