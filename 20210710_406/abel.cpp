// Date: Tue Nov  2 15:35:54 2021

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
  vector<vector<int>> reconstructQueue(vector<vector<int>>& _a) {
    int n = _a.size();
    vector<PII> a(n);

    for (int i = 0; i < n; ++i) a[i] = PII(_a[i][0], _a[i][1]);

    vector<bool> vis(n, false);
    sort(a.begin(), a.end());
    vector<VI> res(n, VI(2, 0));

    for (int i = 0; i < n; ++i) {
      auto t = a[i];
      auto cnt = t.second;

      int cur = -1;
      for (int j = 0; j < n; ++j) {
        if (!vis[j] || res[j][0] == t.first) {
          cur++;
          if (cur == cnt) {
            vis[j] = true;
            res[j] = VI{t.first, t.second};
          }
        }
      }
    }

    return res;
  }
};
