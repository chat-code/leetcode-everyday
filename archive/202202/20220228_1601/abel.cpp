// Date: Mon Feb 28 22:35:31 2022

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
  vector<VI> a;
  int n;
  int res;

  int check(int t) {
    VI b(21, 0);
    int cnt {};

    for (int i = 0; i < 16 && i < a.size(); ++i) {
      if ((t >> i) & 1) {
        cnt++;
        auto v = a[i];
        b[v[0]]--;
        b[v[1]]++;
      }
    }

    for (auto &x : b) {
      if (x) return 0;
    }
    return cnt;
  }

  int get1(int n) {
    int res {};
    for (int i = n; i; i -= lowbit(i)) {
      res++;
    }
    return res;
  }

  int lowbit(int n) {
    return n & -n;
  }

  int maximumRequests(int n, vector<vector<int>>& requests) {
    a = requests;
    n = 0;
    for (auto &v : a) {
      int tmp = max(v[0], v[1]);
      n = max(n, tmp);
    }
    res = 0;

    for (int i = 0; i < (1 << a.size()); ++i) {
      if (res >= get1(i)) continue;
      res = max(res, check(i));
    }

    return res;
  }
};
