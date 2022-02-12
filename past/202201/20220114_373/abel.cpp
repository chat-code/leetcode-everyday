// Date: Fri Jan 14 09:46:04 2022

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

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
    int n = a.size(), m = b.size();
    vector<VI> res;

    priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> q;

    for (int i = 0; i < m; ++i) q.push({a[0] + b[i], {0, i}});

    while (!q.empty() && res.size() < k) {
      auto p = q.top().second;
      q.pop();

      int i = p.first, j = p.second;
      res.push_back({a[i], b[j]});

      if (i + 1 < n) q.push({a[i + 1] + b[j], {i + 1, j}});
    }

    return res;
  }
};
