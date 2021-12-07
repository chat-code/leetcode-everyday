// Date: Tue Dec  7 23:28:55 2021

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

const int N = 210, M = 40010;
ll idx, h[N], st[N], dis[N], cnt[N], n;
int e[M], ne[M], w[M];

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(st, 0, sizeof st);
  memset(dis, 0x3f, sizeof dis);
  memset(cnt, 0, sizeof cnt);
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
  dis[0] = 0;
  cnt[0] = 1;

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
  q.push({0, 0});

  while (!q.empty()) {
    auto t = q.top();
    q.pop();

    ll ver = t.second, base = t.first;

    if (st[ver]) continue;

    st[ver] = 1;

    for (int i = h[ver]; i != -1; i = ne[i]) {
      ll j = e[i], tmp = base + w[i];
      if (tmp < dis[j]) {
        dis[j] = tmp;
        q.push({tmp, j});
        cnt[j] = cnt[ver];
      } else if (tmp == dis[j]) {
        cnt[j] = (cnt[ver] + cnt[j]) % MOD;
      }
    }
  }

  return cnt[n - 1];
}

class Solution {
public:
  int countPaths(int n_, vector<vector<int>>& a) {
    Init();
    n = n_;

    for (auto &v : a) {
      int a = v[0], b = v[1], c = v[2];
      Add(a, b, c);
      Add(b, a, c);
    }

    return dijkstra();
  }
};
