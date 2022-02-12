// Date: Sat Jan 15 18:14:54 2022

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
  bool check(string s) {
    return s[0] == s[1];
  }

  int longestPalindrome(vector<string>& words) {
    map<string, int> m;

    for (auto &s : words) m[s]++;

    int res {};
    bool flag {};
    set<string> vis;

    for (auto &p : m) {
      string s = p.first;
      int cnt = p.second;
      if (!cnt) continue;
      if (vis.find(s) != vis.end()) continue;
      vis.insert(s);

      if (check(s)) {
        if (cnt % 2 == 0) {
          res += cnt * 2;
        } else {
          flag = true;
          res += (cnt - 1) * 2;
        }
      } else {
        string s1 = s;
        swap(s1[0], s1[1]);
        if (m.find(s1) == m.end()) continue;
        vis.insert(s1);

        int cnt1 = m[s1];
        int cur = min(cnt1, cnt);
        res += cur * 4;
      }
    }

    if (flag) res += 2;

    return res;
  }
};
