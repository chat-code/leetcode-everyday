// Date: Mon Nov 15 18:08:38 2021

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

const int N = 110, M = 10010;
int n, m, s, h[N], st[N], dis[N];
int idx, e[M], ne[M], w[M];

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(dis, 0x3f, sizeof dis);
  memset(st, 0, sizeof st);
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa() {
  dis[s] = 0;
  st[s] = 1;

  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    auto t = q.front(); q.pop();
    st[t] = 0;

    int base = dis[t];

    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i], tmp = base + w[i];
      if (tmp < dis[j]) {
        dis[j] = tmp;
        if (!st[j]) {
          st[j] = 1;
          q.push(j);
        }
      }
    }
  }
}

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& a, int _n, int _k) {
    Init();
    m = a.size();
    n = _n;

    for (auto &v : a) {
      Add(v[0], v[1], v[2]);
    }

    s = _k;
    spfa();

    int res = -1;
    for (int i = 1; i <= n; ++i) res = max(res, dis[i]);

    return res == INF ? -1 : res;
  }
};
