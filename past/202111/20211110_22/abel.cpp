// Date: Wed Nov 10 23:02:44 2021

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
  vector<string> res;
  int n;

  void dfs(string cur, int l, int r) {
    if (l > n || r > n) return;

    if (l < r) {
      return;
    } else if (l == r) {
      if (l == n) {
        res.push_back(cur);
      } else {
        dfs(cur + '(', l + 1, r);
      }
    } else {
      if (l < n) dfs(cur + '(', l + 1, r);
      dfs(cur + ')', l, r + 1);
    }
  }

  vector<string> generateParenthesis(int _n) {
    n = _n;
    dfs("", 0, 0);

    return res;
  }
};
