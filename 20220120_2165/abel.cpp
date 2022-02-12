// Date: Sun Feb  6 10:27:50 2022

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
  VI get_min(VI a) {
    sort(a.begin(), a.end());
    VI res;
    int n = a.size(), cnt0 {};

    int i = 0;
    while (i < n && !a[i]) {
      ++i; ++cnt0;
    }

    if (i < n) {
      res.push_back(a[i++]);
      while (cnt0--) res.push_back(0);
    }

    while (i < n) {
      res.push_back(a[i++]);
    }

    return res;
  }

  VI get_max(VI a) {
    sort(a.begin(), a.end(), greater<int>());
    return a;
  }

  VI convert2(ll n) {
    VI res;
    if (n == 0) return VI {0};

    while (n) {
      res.push_back(n % 10);
      n /= 10;
    }
    return res;
  }

  ll convert1(VI a) {
    ll res {};
    int n = a.size();

    for (int i = 0; i < n; ++i) {
      res = res * 10 + a[i];
    }

    return res;
  }

  long long smallestNumber(long long num) {
    if (!num) return num;

    int sign = 1;

    if (num < 0) {
      sign = -1;
      num = -num;
    }

    if (sign > 0) {
      return convert1(get_min(convert2(num)));
    } else {
      return -convert1(get_max(convert2(num)));
    }

    return 0;
  }
};
