 // Date: Sun Oct 31 23:21:58 2021

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
int d[N][2];

class Solution {
public:
  int wiggleMaxLength(vector<int>& a) {
    int n = a.size(), res = 1;
    memset(d, 0, sizeof d);
    for (int i = 0; i < n; ++i) d[i][0] = d[i][1] = 1;

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (a[i] > a[j]) {
          d[i][0] = max(d[i][0], d[j][1] + 1);
        } else if (a[i] < a[j]) {
          d[i][1] = max(d[i][1], d[j][0] + 1);
        } else {
          d[i][0] = max(d[i][0], d[j][0]);
          d[i][1] = max(d[i][1], d[j][1]);
        }
      }
      res = max(max(d[i][0], d[i][1]),
                res);
    }

    return res;
  }
};
