// Date: Sat Mar 26 11:26:52 2022

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
  int n, m;

  vector<vector<int>> imageSmoother(vector<vector<int>>& a) {
    n = a.size(), m = a[0].size();
    vector<VI> b(n, VI(m, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int cnt = 1, sum = a[i][j];
        for (int k = 0; k < 8; ++k) {
          int i1 = i + dir[k][0], j1 = j + dir[k][1];
          if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m) {
            cnt++;
            sum += a[i1][j1];
          }
        }
        b[i][j] = sum / cnt;
      }
    }

    return b;
  }
};
