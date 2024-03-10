// Date: Sun Jan 23 10:46:58 2022

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
  vector<VI> a;
  int n, res;
  vector<bool> vis;
  vector<bool> people;

  void set_people(int idx) {
    for (int j = 0; j < n; ++j) {
      if (a[idx][j] == 0) {
        if (!vis[j]) {
          vis[j] = true;
          people[j] = false;
        }
      } else if (a[idx][j] == 1) {
        if (!vis[j]) {
          vis[j] = true;
          people[j] = true;
        }
      }
    }
  }

  bool check_people(int idx) {
    bool flag = true;

    if (people[idx]) {
      for (int j = 0; j < n; ++j) {
        if (a[idx][j] == 0) {
          if (vis[j] && people[j]) {
            flag = false;
            break;
          }
        } else if (a[idx][j] == 1) {
          if (vis[j] && !people[j]) {
            flag = false;
            break;
          }
        }
      }
    }

    return flag;
  }

  void dfs(int idx, int cur) {
    if (idx == n) {
      res = max(res, cur);
      return;
    }

    vector<bool> people_bak = people;
    vector<bool> vis_bak = vis;

    if (vis[idx]) {
      if (people[idx]) {
        if (check_people(idx)) {
          set_people(idx);
          dfs(idx + 1, cur + 1);

          vis = vis_bak;
          people = people_bak;

          return;
        } else {
          return;
        }
      } else {
        dfs(idx + 1, cur);
        return;
      }
    }

    vis[idx] = true;
    people[idx] = true;

    if (check_people(idx)) {
      set_people(idx);
      dfs(idx + 1, cur + 1);
    } else {
      ;
    }

    people = people_bak;
    vis = vis_bak;
    vis[idx] = true;
    people[idx] = false;
    dfs(idx + 1, cur);

    people = people_bak;
    vis = vis_bak;
  }

  int maximumGood(vector<vector<int>>& _a) {
    a = _a;
    n = a.size();
    res = 0;
    vis = vector<bool>(n, false);
    people = vector<bool>(n, false);

    dfs(0, 0);

    return res;
  }
};
