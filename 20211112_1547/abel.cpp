// Date: Fri Nov 12 14:50:35 2021

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

const int N = 110;
int d[N][N];

class Solution {
public:
  int minCost(int n, vector<int>& b) {
    memset(d, 0x3f, sizeof d);
    int len = b.size();
    int m = len + 2;

    VI a(m, 0);
    a[0] = 0;
    a[m - 1] = n;

    sort(b.begin(), b.end());
    for (int i = 0; i < b.size(); ++i) a[i + 1] = b[i];

    for (int i = 0; i < m - 1; ++i) d[i][i + 1] = 0;

    for (int k = 3; k <= m; ++k) {
      for (int i = 0; i + k - 1 < m; ++i) {
        int j = i + k - 1;
        for (int s = i + 1; s < j; ++s) {
          d[i][j] = min(d[i][s] + d[s][j] + a[j] - a[i], d[i][j]);
        }
      }
    }

    return d[0][m - 1];
  }
};
