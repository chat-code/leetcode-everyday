// Date: Mon Nov 15 17:32:21 2021

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

const int N = 1010;
int fa[N], sz[N];

void Init() {
  for (int i = 0; i < N; ++i) {
    fa[i] = i;
    sz[i] = 1;
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
  vector<bool> friendRequests(int n, vector<vector<int>>& a, vector<vector<int>>& b) {
    Init();
    int m = b.size();
    vector<bool> res(m, false);

    for (int i = 0; i < m; ++i) {
      auto &v = b[i];
      int x = v[0], y = v[1];

      bool flag = true;
      int x1 = Find(x), y1 = Find(y);

      for (int j = 0; j < a.size(); ++j) {
        auto &v1 = a[j];
        int x2 = v1[0], y2 = v1[1];
        int x3 = Find(x2), y3 = Find(y2);

        if ((PII(x1, y1) == PII(x3, y3)) || (PII(x1, y1) == PII(y3, x3))) {
          flag = false;
          break;
        }
      }

      if (flag) Union(x, y);

      res[i] = flag;
    }

    return res;
  }
};
