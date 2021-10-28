// Date: Thu Oct 28 18:45:57 2021

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

const int N = 1010;
int d[N][N];

class Solution {
public:
  int longestCommonSubsequence(string a, string b) {
    memset(d, 0, sizeof d);
    int n = a.size(), m = b.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i] == b[j]) {
          if (i && j) d[i][j] = d[i - 1][j - 1] + 1;
          else d[i][j] = 1;
        } else {
          if (i && j) d[i][j] = max(d[i - 1][j], d[i][j - 1]);
          else if (i) d[i][j] = d[i - 1][j];
          else if (j) d[i][j] = d[i][j - 1];
        }
      }
    }

    return d[n - 1][m - 1];
  }
};
