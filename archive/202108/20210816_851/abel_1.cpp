// Date: Fri Dec 31 10:34:24 2021

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

const int N = 600, M = 300010;
int idx, h[N], d[N], n, q[N];
int e[M], ne[M];

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
  vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    n = quiet.size();

    Init();

    for (auto &v : richer) {
      Add(v[0], v[1]);
      d[v[1]]++;
    }

    VI res(n);
    for (int i = 0; i < n; ++i) res[i] = i;

    int hh = 0, tt = -1;

    for (int i = 0; i < n; ++i) {
      if (!d[i]) q[++tt] = i;
    }

    while (hh <= tt) {
      int t = q[hh++];

      for (int i = h[t]; i != -1; i = ne[i]) {
        int j = e[i];
        if (quiet[res[t]] < quiet[res[j]]) res[j] = res[t];
        d[j]--;
        if (!d[j]) q[++tt] = j;
      }
    }

    return res;
  }
};
