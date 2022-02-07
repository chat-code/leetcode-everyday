// Date: Mon Feb  7 22:20:03 2022

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
  using PIC = pair<int, char>;

  string longestDiverseString(int a, int b, int c) {
    string res;
    priority_queue<PIC, vector<PIC>, less<PIC>> q;
    if (a) q.push({a, 'a'});
    if (b) q.push({b, 'b'});
    if (c) q.push({c, 'c'});

    while (!q.empty()) {
      auto t = q.top(); q.pop();
      auto ch = t.second;
      auto cnt = t.first;

      int sz = res.size();
      if (!(sz >= 2 && res[sz - 1] == ch && res[sz - 1] == res[sz - 2])) {
        res += ch;
        if (cnt - 1) q.push({cnt - 1, ch});
      } else {
        if (!q.empty()) {
          auto t1 = q.top(); q.pop();

          ch = t1.second;
          cnt = t1.first;
          res += ch;

          if (cnt - 1) q.push({cnt - 1, ch});
          q.push(t);
        } else break;
      }
    }

    return res;
  }
};
