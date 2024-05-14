// Date: Tue Nov 16 21:06:55 2021

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

const int N = 10010, M = 40010;
int h[N], q[N], hh, tt, n, d[N];
int idx, e[M], ne[M];

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(d, 0, sizeof d);
}

void Add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
  void topsort() {
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
      if (!d[i]) q[++tt] = i;
    }

    while (tt >= hh) {
      int t = q[hh++];
      for (int i = h[t]; i != -1; i = ne[i]) {
        int j = e[i];
        d[j]--;
        if (!d[j]) q[++tt] = j;
      }
    }
  }

  vector<int> eventualSafeNodes(vector<vector<int>>& g) {
    n = g.size();
    Init();

    for (int i = 0; i < n; ++i) {
      for (auto &j : g[i]) {
        Add(j, i);
        d[i]++;
      }
    }

    VI res;
    topsort();
    for (int i = 0; i <= tt; ++i) res.push_back(q[i]);
    sort(res.begin(), res.end());

    return res;
  }
};
