// Date: Tue Nov 16 15:48:08 2021

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

const int N = 20010, M = 80010;
int n, m, h[N],st[N], cnt[N];
ll dis[N];
int idx, e[M], ne[M], w[M];

void Init() {
  idx = 0;
  memset(dis, 0x3f, sizeof dis);
  memset(st, 0, sizeof st);
  memset(h, -1, sizeof h);
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
  dis[n] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({0, n});

  while (!q.empty()) {
    auto t = q.top(); q.pop();
    int ver = t.second;
    ll base = t.first;
    if (st[ver]) continue;

    st[ver] = 1;

    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i];
      ll tmp = base + w[i];
      if (tmp < dis[j]) {
        dis[j] = tmp;
        q.push({tmp, j});
      }
    }
  }
}

class Solution {
public:
  int countRestrictedPaths(int _n, vector<vector<int>>& edges) {
    n = _n;
    m = edges.size();
    Init();
    for (auto &v : edges) {
      int a = v[0], b = v[1], w = v[2];
      Add(a, b, w);
      Add(b, a, w);
    }

    dijkstra();

    vector<PII> v;
    for (int i = 1; i <= n; ++i) v.push_back({dis[i], i});
    sort(v.begin(), v.end());

    memset(cnt, 0, sizeof cnt);
    cnt[n] = 1;

    for (auto &p : v) {
      int x = p.second, y = p.first;
      for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (dis[j] > y) {
          cnt[j] = (cnt[j] + cnt[x]) % MOD;
        }
      }
    }

    return cnt[1];
  }
};
