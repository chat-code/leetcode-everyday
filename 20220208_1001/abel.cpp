// Date: Tue Feb  8 07:35:52 2022

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
  int n;
  set<PII> vis;
  map<PII, int> cnt;
  map<int, int> row, col, d1, d2;

  bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
  }

  void turn_on(int x, int y) {
    row[x]++;
    col[y]++;
    d1[x + y]++;
    d2[x - y]++;
  }

  void turn_off(int x, int y) {
    auto t = PII(x, y);
    if (vis.find(t) != vis.end()) {
      vis.erase(t);
      row[x]--;
      col[y]--;
      d1[x + y]--;
      d2[x - y]--;
    }
  }

  int query(int x, int y) {
    int res = (row[x] || col[y] || d1[x + y] | d2[x - y]);
    turn_off(x, y);

    for (int i = 0; i < 8; ++i) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1)) {
        turn_off(x1, y1);
      }
    }

    return res;
  }

  vector<int> gridIllumination(int _n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    n = _n;
    for (auto &v : lamps) {
      int x = v[0], y = v[1];
      auto t = PII(x, y);

      if (vis.find(t) == vis.end()) {
        vis.insert(t);
        turn_on(x, y);
      }
    }

    VI res;

    for (auto &v : queries) {
      int x = v[0], y = v[1];
      res.push_back(query(x, y));
    }

    return res;
  }
};
