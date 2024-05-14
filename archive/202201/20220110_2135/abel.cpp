// Date: Sat Jan 15 13:17:51 2022

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
  ull Hash(string &s) {
    ull r = 0;
    for (auto &c : s) r = r * Pr + c;
    return r;
  }

  int wordCount(vector<string>& a, vector<string>& b) {
    unordered_set<ull> vis;

    for (auto &s : a) {
      bool st[26] {};
      for (auto &c : s) st[c - 'a'] = true;

      for (char c = 'a'; c <= 'z'; ++c) {
        if (!st[c - 'a']) {
          string s1 = s + c;
          sort(s1.begin(), s1.end());
          vis.insert(Hash(s1));
        }
      }
    }

    int res {};

    for (auto &s : b) {
      string s1 = s;
      sort(s1.begin(), s1.end());

      if (vis.find(Hash(s1)) != vis.end()) {
        res++;
      }
    }

    return res;
  }
};
