// Date: Sun Oct 31 18:49:08 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

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
  vector<VI> res;
  VI tmp;
  string s;
  int n;

  string conver(VI &v) {
    string r;
    for (int i = 0; i < 3; ++i) r += to_string(v[i]) + ".";
    r += to_string(v[3]);
    return r;
  }

  void dfs(int idx, int cur) {
    if (tmp.size() > 4) return;

    if (idx == n) {
      if (tmp.size() == 4) {
        res.push_back(tmp);
      }
      return;
    }

    for (int i = idx; i < n; ++i) {
      cur = cur * 10 + (s[i] - '0');

      if (!cur) {
        tmp.push_back(cur);
        dfs(i + 1, 0);
        tmp.pop_back();
        return;
      } else if (cur >= 1 && cur <= 255) {
        tmp.push_back(cur);
        dfs(i + 1, 0);
        tmp.pop_back();
      } else break;
    }
  }

  vector<string> restoreIpAddresses(string _s) {
    s = _s;
    n = s.size();

    dfs(0, 0);

    vector<string> res2;

    for (auto &v : res) {
      res2.push_back(conver(v));
    }
    return res2;
  }
};
