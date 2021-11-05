// Date: Fri Nov  5 23:54:43 2021

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
  int n, d;

  bool check(int m) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > m) return false;

      int j = i, sum = 0;
      while (j < n && sum + a[j] <= m) {
        sum += a[j];
        ++j;
      }
      i = j - 1;
      cnt++;

      if (cnt > d) return false;
    }
    return true;
  }

  int shipWithinDays(vector<int>& _a, int _d) {
    a = _a; d = _d;
    n = a.size();
    int l = 1, r = 3e7, mid;
    while (l < r) {
      mid = (l + r) / 2;

      if (check(mid)) r = mid;
      else l = mid + 1;
    }

    return r;
  }
};
