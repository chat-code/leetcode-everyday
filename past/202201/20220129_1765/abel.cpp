// Date: Sat Jan 29 09:20:20 2022

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
  vector<vector<int>> highestPeak(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<VI> res(n, VI(m, 0));

    queue<PII> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j]) {
          q.push({i, j});
          vis[i][j] = true;
          res[i][j] = 0;
        }
      }
    }

    while (!q.empty()) {
      auto t = q.front(); q.pop();
      int x = t.first, y = t.second, x1, y1;

      for (int i = 0; i < 4; ++i) {
        x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && !vis[x1][y1]) {
          vis[x1][y1] = true;
          res[x1][y1] = res[x][y] + 1;
          q.push({x1, y1});
        }
      }
    }

    return res;
  }
};
