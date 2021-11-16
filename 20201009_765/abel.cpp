// Date: Tue Nov 16 21:50:03 2021

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

const int N = 100;
int fa[N], sz[N], n;

void Init() {
  for (int i = 0; i < n; ++i) {
    sz[i] = 1;
    fa[i] = i;
  }
}

int Find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = Find(fa[x]);
}

void Union(int x, int y) {
  int rx = Find(x), ry = Find(y);
  if (rx == ry) return;
  fa[ry] = rx;
  sz[rx] += sz[ry];
}

class Solution {
public:
  int minSwapsCouples(vector<int>& row) {
    n = row.size() / 2;
    Init();
    for (int i = 0; i < n; ++i) {
      int j = i * 2, j1 = j + 1;
      int x = row[j] / 2, y = row[j1] / 2;
      int rx = Find(x), ry = Find(y);
      if (rx == ry) continue;
      Union(rx, ry);
    }

    int res {};
    unordered_map<int, int> s;
    for (int i = 0; i < n; ++i) {
      int r = Find(i);
      s[r] = sz[r];
    }

    for (auto &p : s) {
      res += p.second - 1;
    }

    return res;
  }
};
