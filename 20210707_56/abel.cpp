// Date: Tue Nov  2 22:37:10 2021

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
  vector<vector<int>> merge(vector<vector<int>>& a) {
    vector<VI> res;
    int n = a.size();

    sort(a.begin(), a.end(), [&](const VI &x, const VI &y) {
      return x[0] < y[0];
    });

    int r = a[0][1], l = a[0][0];
    bool flag = true;

    for (int i = 1; i < n; ++i) {
      while (i < n && a[i][0] <= r) {
        r = max(r, a[i][1]);
        l = min(l, a[i][0]);
        ++i;
      }

      res.push_back({l, r});
      flag = false;
      if (i < n) {
        l = a[i][0], r = a[i][1];
        flag = true;
      }
    }

    if (flag) res.push_back({l, r});

    return res;
  }
};
