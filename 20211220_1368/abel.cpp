// Date: Mon Dec 20 13:50:07 2021

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
  int minCost(vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size();
    int sz = n * m + 10;

    VI dis(sz, INF), st(sz, 0);
    dis[0] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 0});

    auto check = [&](int i, int j) -> bool {
      return i >= 0 && i < n &&
        j >= 0 && j < m;
    };

    while (!q.empty()) {
      auto t = q.top();
      q.pop();

      int ver = t.second, base = t.first;
      if (st[ver]) continue;
      st[ver] = 1;

      int x = ver / m, y = ver % m;

      for (int i = 0; i < 4; ++i) {
        int x1 = x + dir[i][0], y1 = y + dir[i][1], p = x1 * m + y1;

        if (check(x1, y1)) {
          int tmp = base + (i + 1 != g[x][y]);
          if (tmp < dis[p]) {
            dis[p] = tmp;
            q.push({dis[p], p});
          }
        }
      }
    }

    return dis[n * m - 1];
  }
};
