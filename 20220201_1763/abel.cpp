// Date: Tue Feb  1 08:51:39 2022

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
  string res;
  string s;

  bool check(int i, int j) {
    bool vis[256] {};

    for (int k = i; k <= j; ++k) vis[s[k]] = true;
    for (int k = i; k <= j; ++k) {
      if (isupper(s[k])) {
        if (!vis[tolower(s[k])]) return false;
      } else if (islower(s[k])) {
        if (!vis[toupper(s[k])]) return false;
      }
    }

    return true;
  }

  string longestNiceSubstring(string _s) {
    s = _s;
    res = "";
    int n = s.size();

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (check(i, j)) {
          int len = j - i + 1;
          if (len > res.size()) {
            res = s.substr(i, len);
          }
        }
      }
    }

    return res;
  }
};
