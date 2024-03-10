// Date: Thu Feb 17 19:32:23 2022

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
  {1, 2}, {1, -2},
  {-1, 2}, {-1, -2},
  {2, 1}, {2, -1},
  {-2, 1}, {-2, -1},
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

const int N = 30;
double d[110][N][N];

class Solution {
public:
  double knightProbability(int n, int k, int row, int column) {
    memset(d, 0, sizeof d);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        d[0][i][j] = 1;
      }
    }

    for (int s = 1; s <= k; ++s) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          for (int idx = 0; idx < 8; ++idx) {
            int i1 = i + dir[idx][0], j1 = j + dir[idx][1];
            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n) {
              d[s][i][j] += d[s - 1][i1][j1] / 8;
            }
          }
        }
      }
    }

    return d[k][row][column];
  }
};
