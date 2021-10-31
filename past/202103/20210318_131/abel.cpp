// Date: Sat Oct 30 15:56:23 2021

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

const int N = 20;
bool d[N][N];

class Solution {
public:
  string s;
  int n;
  vector<vector<string>> res;
  vector<string> tmp;

  void dfs(int idx) {
    if (idx == n) {
      res.push_back(tmp);
      return;
    }

    for (int i = idx; i < n; ++i) {
      if (d[idx][i]) {
        tmp.push_back(s.substr(idx, i - idx + 1));
        dfs(i + 1);
        tmp.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string _s) {
    s = _s;
    n = s.size();
    memset(d, false, sizeof d);

    for (int i = 0; i < n; ++i) d[i][i] = true;

    for (int k = 2; k <= n; ++k) {
      for (int i = 0; i + k - 1 < n; ++i) {
        int j = i + k - 1;
        if (s[i] == s[j]) {
          if (j - i == 1) d[i][j] = true;
          else d[i][j] = d[i + 1][j - 1];
        } else d[i][j] = false;
      }
    }

    dfs(0);

    return res;
  }
};
