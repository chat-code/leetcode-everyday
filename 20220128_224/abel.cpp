// Date: Mon Jan 31 13:00:08 2022

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
  string s;
  int n;
  stack<int> sign;

  int get_num(int &i) {
    int res = 0;
    while (i < n && isdigit(s[i])) {
      res = res * 10 + (s[i] - '0');
      ++i;
    }

    return res;
  }

  void skip(int &i) {
    while (i < n && isspace(s[i])) ++i;
  }

  int calculate(string _s) {
    s = _s;
    int res {}, cur = 1, pre = 1;
    n = s.size();
    sign.push(1);

    for (int i = 0; i < n; ++i) {
      skip(i);
      if (i >= n) break;

      if (s[i] == '(') {
        cur = pre;
        sign.push(cur);
      } else if (isdigit(s[i])) {
        int x = get_num(i);
        res += x * pre;
        --i;
      } else if (s[i] == ')') {
        sign.pop();
        cur = sign.top();
        pre = cur;
      } else if (s[i] == '+') {
        pre = cur;
      } else if (s[i] == '-') {
        pre = -cur;
      }
    }

    return res;
  }
};
