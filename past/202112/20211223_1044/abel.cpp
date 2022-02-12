// Date: Thu Dec 30 08:48:22 2021

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
  vector<ull> p;
  vector<ull> h;
  int n;

  string longestDupSubstring(string s) {
    n = s.size();
    p = vector<ull>(n + 1, 0);
    h = vector<ull>(n + 1, 0);

    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
      p[i] = p[i - 1] * Pr;
      h[i] = h[i - 1] * Pr + s[i - 1];
    }

    int l = 1, r = n - 1, mid;
    while (l < r) {
      mid = (l + r + 1) / 2;
      if (check(mid) != -1) l = mid;
      else r = mid - 1;
    }

    int idx = check(l);
    if (idx != -1) {
      return s.substr(idx, l);
    } else return "";
  }

  int check(int k) {
    unordered_set<ull> se;

    for (int i = 1; i + k - 1 <= n; ++i) {
      int j = i + k - 1;
      ull x = h[j] - h[i - 1] * p[j - i + 1];

      if (se.find(x) != se.end()) return i - 1;
      se.insert(x);
    }

    return -1;
  }
};
