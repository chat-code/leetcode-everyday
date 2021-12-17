// Date: Fri Dec 17 21:35:16 2021

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
  int cnt[26];

  bool check(string &s) {
    int m[26] {};

    for (auto &c : s) {
      if (isalpha(c)) {
        m[tolower(c) - 'a']++;
      }
    }

    for (int i = 0; i < 26; ++i) {
      if (m[i] < cnt[i]) return false;
    }

    return true;
  }

  string shortestCompletingWord(string a, vector<string>& b) {
    memset(cnt, 0, sizeof cnt);

    for (auto &c : a) {
      if (isalpha(c)) {
        cnt[tolower(c) - 'a']++;
      }
    }

    string res;

    for (auto &s : b) {
      if (check(s)) {
        if (res.empty() || s.size() < res.size())
          res = s;
      }
    }

    return res;
  }
};
