// Date: Sun Nov  7 18:45:31 2021

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
  VI p1, p2;

  bool check() {
    for (int i = 0; i < 300; ++i) {
      if (p1[i] < p2[i]) return false;
    }
    return true;
  }

  string minWindow(string s, string t) {
    int n = s.size(), m = t.size();
    p1 = VI(300, 0), p2 = VI(300, 0);
    int start = -1, len = n + 1;

    for (int i = 0; i < m; ++i) p2[t[i]]++;

    for (int i = 0, j = 0; j < n; ++j) {
      p1[s[j]]++;

      while (i <= j && check()) {
        int tmp = j - i + 1;
        if (tmp < len) {
          len = tmp;
          start = i;
        }
        p1[s[i]]--;
        ++i;
      }
    }

    if (start == -1) return "";
    return s.substr(start, len);
  }
};
