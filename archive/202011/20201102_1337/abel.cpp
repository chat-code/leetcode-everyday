// Date: Sat Nov  6 00:22:16 2021

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

class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>>& a, int k) {
    vector<PII> p;
    VI res(k, -1);

    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; ++i) {
      int l = 0, r = m - 1, mid;
      while (l < r) {
        mid = (l + r + 1) / 2;
        if (a[i][mid] == 1) l = mid;
        else r = mid - 1;
      }
      if (a[i][l] == 1) p.push_back({l + 1, i});
      else p.push_back({l, i});
    }

    sort(p.begin(), p.end());
    for (int i = 0; i < k; ++i) res[i] = p[i].second;

    return res;
  }
};
