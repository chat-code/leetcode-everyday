// Date: Sat Oct 30 17:22:35 2021

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

typedef ListNode LN;
typedef LN* LNP;
typedef TreeNode TN;
typedef TN* TNP;

const int N = 210;

class Solution {
public:
  VI a;
  int n;
  vector<VI> res;
  VI tmp;

  void dfs(int idx) {
    if (idx == n) {
      return;
    }

    bool vis[N] {};
    for (int i = idx; i < n; ++i) {
      if (vis[a[i] + 100] || (!tmp.empty() && a[i] < tmp.back()))
        continue;

      vis[a[i] + 100] = true;

      tmp.push_back(a[i]);
      if (tmp.size() >= 2) res.push_back(tmp);

      dfs(i + 1);

      tmp.pop_back();
    }
  }

  vector<vector<int>> findSubsequences(vector<int>& _a) {
    a = _a; n = a.size();

    dfs(0);

    return res;
  }
};
