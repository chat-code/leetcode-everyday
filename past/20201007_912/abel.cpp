// Date: Thu Dec  9 09:45:36 2021

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

const int N = 50010;
int h[N], idx;

void down(int u) {
  int t = u, l = u * 2, r = u * 2 + 1;
  if (l <= idx && h[l] < h[t]) t = l;
  if (r <= idx && h[r] < h[t]) t = r;
  if (t != u) {
    swap(h[t], h[u]);
    down(t);
  }
}

void up(int u) {
  while (u / 2 && h[u / 2] > h[u]) {
    swap(h[u], h[u / 2]);
    u /= 2;
  }
}

class Solution {
public:
  vector<int> sortArray(vector<int>& a) {
    int n = a.size();
    idx = n;

    for (int i = 0; i < a.size(); ++i) h[i + 1] = a[i];

    for (int i = n / 2; i > 0; --i) down(i);

    for (int i = 0; i < n; ++i) {
      a[i] = h[1];
      swap(h[1], h[idx]);
      idx--;
      down(1);
    }

    return a;
  }
};
