// Date: Sat Dec 18 08:45:16 2021

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
  vector<int> maxSumOfThreeSubarrays(vector<int>& a, int k) {
    int n = a.size();
    vector<VI> d(n + 1, VI(4, 0));
    VI p(n + 1, 0);

    for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i];
    for (int i = k; i <= n; ++i) {
      for (int j = 1; j <= 3; ++j) {
        int x = d[i - 1][j], y = d[i - k][j - 1] + p[i] - p[i - k];
        if (x > y) {
          d[i][j] = x;
        } else {
          d[i][j] = y;
        }
      }
    }

    VI res;
    int i = n, j = 3;

    while (j >= 1) {
      int x = d[i - 1][j], y = d[i - k][j - 1] + p[i] - p[i - k];
      if (x == d[i][j]) --i;
      else {
        res.push_back(i - k);
        i -= k;
        --j;
      }
    }

    reverse(res.begin(), res.end());

    return res;
  }
};
