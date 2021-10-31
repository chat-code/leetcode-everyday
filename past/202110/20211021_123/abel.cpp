// Date: Thu Oct 28 16:03:29 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

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

typedef ListNode LN;
typedef LN* LNP;
typedef TreeNode TN;
typedef TN* TNP;

const int N = 100010;
int d[N][3][3];

class Solution {
public:
  int maxProfit(vector<int>& a) {
    memset(d, 0, sizeof d);
    int n = a.size();

    d[0][1][0] = -a[0];
    d[0][1][1] = d[0][0][1] = d[0][0][2] = d[0][1][1] = -INF;
    for (int i = 1; i < n; ++i) {
      d[i][0][1] = max(d[i - 1][1][0] + a[i], d[i - 1][0][1]);
      d[i][0][2] = max(d[i - 1][1][1] + a[i], d[i - 1][0][2]);
      d[i][1][0] = max(d[i - 1][0][0] - a[i], d[i - 1][1][0]);
      d[i][1][1] = max(d[i - 1][0][1] - a[i], d[i - 1][1][1]);
    }

    return max(d[n - 1][0][2], max(d[n - 1][0][1], 0));
  }
};
