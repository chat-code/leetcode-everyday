// Date: Tue Nov  9 11:06:01 2021

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
  VI a;
  int n;

  int maxSumTwoNoOverlap(vector<int>& _a, int L, int M) {
    n = _a.size(); a = _a;
    int res {};
    VI p1(n + 10, 0), d1(n + 10, 0), d2(n + 10, 0);
    for (int i = 0; i < n; ++i) p1[i + 1] = p1[i] + a[i];

    for (int i = L; i <= n; ++i) d1[i] = max(d1[i - 1], p1[i] - p1[i - L]);
    for (int i = n - M + 1; i >= 1; --i) d2[i] = max(d2[i + 1], p1[i + M - 1] - p1[i - 1]);
    for (int i = L; i <= n - M; ++i) res = max(res, d1[i] + d2[i + 1]);

    fill(d1.begin(), d1.end(), 0); fill(d2.begin(), d2.end(), 0);
    for (int i = M; i <= n; ++i) d1[i] = max(d1[i - 1], p1[i] - p1[i - M]);
    for (int i = n - L + 1; i >= 1; --i) d2[i] = max(d2[i + 1], p1[i + L - 1] - p1[i - 1]);
    for (int i = M; i <= n - L; ++i) res = max(res, d1[i] + d2[i + 1]);

    return res;
  }
};
