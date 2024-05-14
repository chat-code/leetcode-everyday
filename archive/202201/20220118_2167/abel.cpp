// Date: Sun Feb  6 14:52:32 2022

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
  int minimumTime(string s) {
    int n = s.size();
    VI pre(n, INF), post(n, INF);
    int res = INF;

    pre[0] = (s[0] == '1');
    for (int i = 1; i < n; ++i) {
      if (s[i] == '1') {
        pre[i] = min(pre[i - 1] + 2, i + 1);
      } else {
        pre[i] = pre[i - 1];
      }
    }

    post[n - 1] = (s[n - 1] == '1');
    for (int i = n - 2; i >= 0; --i) {
      if (s[i] == '1') {
        post[i] = min(post[i + 1] + 2, n - i);
      } else {
        post[i] = post[i + 1];
      }
    }

    res = pre[n - 1];
    for (int i = 0; i < n - 1; ++i) {
      res = min(res, pre[i] + post[i + 1]);
    }

    return res;
  }
};
