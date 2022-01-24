// Date: Mon Jan 24 22:42:22 2022

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

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
int h[N], dis[N], dis1[N];
int e[M], ne[M], idx;
int step, change;

void Init() {
  idx = 0;
  memset(dis, 0x3f, sizeof dis);
  memset(dis1, 0x3f, sizeof dis1);
  memset(h, -1, sizeof h);
}

void Add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int s) {
  dis[s] = 0;

  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({0, s});

  while (!q.empty()) {
    auto t = q.top();
    q.pop();
    int ver = t.second, base = t.first;

    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i], tmp = base;
      int k = tmp / change;
      if (k % 2 != 0) {
        tmp += change - (tmp % change);
      }
      tmp += step;

      if (tmp < dis[j]) {
        dis1[j] = dis[j];
        dis[j] = tmp;

        q.push({dis[j], j});
        q.push({dis1[j], j});
      } else if (tmp > dis[j] && tmp < dis1[j]) {
        dis1[j] = tmp;
        q.push({dis1[j], j});
      }
    }
  }
}

class Solution {
public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int _change) {
    step = time;
    change = _change;
    Init();

    for (auto &v : edges) {
      Add(v[0], v[1]);
      Add(v[1], v[0]);
    }

    dijkstra(1);

    return dis1[n];
  }
};
