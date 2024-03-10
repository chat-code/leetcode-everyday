// Date: Wed Feb 16 20:49:38 2022

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
  int checkWays(vector<vector<int>>& _g) {
    unordered_map<int, unordered_set<int>> g;

    for (auto &p : _g) {
      int x = p[0], y = p[1];
      g[x].insert(y);
      g[y].insert(x);
    }

    int n = g.size(), root = -1;
    for (auto &p : g) {
      if (p.second.size() == n - 1) {
        root = p.first;
        break;
      }
    }

    if (root == -1) return 0;

    int res = 1;
    for (auto &[x, ne] : g) {
      if (x == root) continue;

      int cur = ne.size(), parent = -1, psize = INF;

      for (auto &y : ne) {
        auto tmp = g[y].size();
        if (tmp >= cur && tmp < psize) {
          psize = tmp;
          parent = y;
        }
      }

      if (parent == -1) return 0;

      auto pne = g[parent];
      for (auto &y : ne) {
        if (y == parent) continue;
        if (pne.find(y) == pne.end()) return 0;
      }

      if (pne.size() == cur) res = 2;
    }

    return res;
  }
};
