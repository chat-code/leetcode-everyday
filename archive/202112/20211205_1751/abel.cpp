// Date: Mon Dec  6 22:16:06 2021

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
  int maxValue(vector<vector<int>>& a, int k) {
    int n = a.size();

    sort(a.begin(), a.end(), [&](const VI &x, const VI &y) {
      if (x[1] != y[1]) return x[1] < y[1];
      else return x[0] < y[0];
    });

    vector<VI> d(n, VI(k + 1, 0));
    int res = a[0][2];

    for (int i = 0; i < n; ++i) {
      d[i][1] = a[i][2];
      res = max(res, d[i][1]);
    }

    for (int i = 1; i < n; ++i) {
      int start = a[i][0];

      int l = 0, r = i - 1, mid;
      while (l < r) {
        mid = (l + r + 1) / 2;
        if (a[mid][1] < start) l = mid;
        else r = mid - 1;
      }

      if (a[l][1] < start) {
        for (int j = 1; j <= min(k, i + 1); ++j) {
          d[i][j] = max(d[i - 1][j], d[l][j - 1] + a[i][2]);
          res = max(res, d[i][j]);
        }
      } else {
        for (int j = 1; j <= min(k, i + 1); ++j) {
          d[i][j] = max(d[i - 1][j], a[i][2]);
          res = max(res, d[i][j]);
        }
      }
    }

    return res;
  }
};
