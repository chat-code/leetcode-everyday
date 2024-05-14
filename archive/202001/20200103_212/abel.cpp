// Date: Wed Nov 17 11:23:37 2021

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

const int N = 30010 * 10;
int idx, son[N][26], cnt[N];
bool vis[20][20];

void Init() {
  idx = 0;
  memset(son, 0, sizeof son);
  memset(cnt, 0, sizeof cnt);
  memset(vis, false, sizeof vis);
}

void Insert(string &s) {
  int p = 0;
  for (auto &c : s) {
    int u = c - 'a';
    if (!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
  }
  cnt[p]++;
}

bool search(string &s) {
  int p = 0;
  for (auto &c : s) {
    int u = c - 'a';
    if (!son[p][u]) return false;
    p = son[p][u];
  }

  return cnt[p] > 0;
}

class Solution {
public:
  vector<string> res;
  set<string> s;
  int n, m;
  vector<vector<char>> g;

  void dfs(int x, int y, int p, string tmp) {
    vis[x][y] = true;

    int u = g[x][y] - 'a';
    if (son[p][u]) {
      tmp += g[x][y];

      p = son[p][u];
      if (cnt[p] > 0) {
        s.insert(tmp);
      }

      int x1, y1;
      for (int i = 0; i < 4; ++i) {
        x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && !vis[x1][y1]) {
          dfs(x1, y1, p, tmp);
        }
      }
    }

    vis[x][y] = false;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Init();
    for (auto &s : words) Insert(s);

    res.clear();
    g = board;
    n = g.size();
    m = g[0].size();
    s.clear();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        dfs(i, j, 0, "");
      }
    }

    for (auto &c : s) res.push_back(c);

    return res;
  }
};
