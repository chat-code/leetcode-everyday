// Date: Sun Nov  7 23:38:27 2021

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

const int N = 100010;
int q1[N], q2[N];

class Solution {
public:
  int longestSubarray(vector<int>& a, int k) {
    int n = a.size(), res {};

    int hh1 = 0, tt1 = -1, hh2 = 0, tt2 = -1;
    for (int i = 0, j = 0; j < n; ++j) {
      while (tt1 >= hh1 && a[q1[tt1]] > a[j]) --tt1;
      while (tt2 >= hh2 && a[q2[tt2]] < a[j]) --tt2;
      q1[++tt1] = j;
      q2[++tt2] = j;

      while (tt1 >= hh1 && tt2 >= hh2 &&
             a[q2[hh2]] - a[q1[hh1]] > k) {
        if (i == q1[hh1]) ++hh1;
        if (i == q2[hh2]) ++hh2;
        ++i;
      }

      res = max(res, j - i + 1);
    }

    return res;
  }
};
