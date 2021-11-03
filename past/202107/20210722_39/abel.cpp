// Date: Sat Oct 30 13:56:10 2021

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

class Solution {
public:
  VI a, tmp;
  int ta, n;
  vector<VI> res;

  void dfs(int t, int idx) {
    if (!t) {
      res.push_back(tmp);
      return;
    }
    if (t < 0) return;

    for (int i = idx; i < n; ++i) {
      tmp.push_back(a[i]);
      dfs(t - a[i], i);
      tmp.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int>& _a, int _ta) {
    a = _a; ta = _ta; n = a.size();
    dfs(ta, 0);

    return res;
  }
};
