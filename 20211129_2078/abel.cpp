// Date: Sun Nov 21 10:28:46 2021

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
  int maxDistance(vector<int>& a) {
    map<int, PII> m;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
      if (m.find(a[i]) == m.end()) {
        m[a[i]] = PII(i, i);
      } else {
        auto &x = m[a[i]];
        x.first = min(x.first, i);
        x.second = max(x.second, i);
      }
    }

    vector<PII> b;
    for (auto &p : m) {
      b.push_back(p.second);
    }

    int n1 = b.size(), res = 0;

    for (int i = 0; i < n1; ++i) {
      for (int j = 0; j < n1; ++j) {
        if (i == j) continue;
        res = max(res, max(b[i].first - b[j].second,
                           b[i].second - b[j].first));
      }
    }

    return res;
  }
};
