// Date: Wed Dec 29 15:51:02 2021

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
  unordered_set<ull> s;

  vector<string> findAllConcatenatedWordsInADict(vector<string>& a) {
    s.clear();

    for (auto &x : a) {
      ull y {};
      for (auto &c : x) {
        y = y * Pr + c;
      }
      s.insert(y);
    }

    vector<string> res;

    for (auto &x : a) {
      if (check(x)) res.push_back(x);
    }

    return res;
  }

  bool check(const string &str) {
    int n = str.size();
    VI d(n + 1, -INF);

    d[0] = 0;

    for (int i = 1; i <= n; ++i) {
      ull y {};
      if (d[i - 1] < 0) continue;

      for (int j = i; j <= n; ++j) {
        y = y * Pr + str[j - 1];
        if (s.find(y) != s.end()) {
          d[j] = max(d[j], d[i - 1] + 1);
        }
      }

      if (d[n] > 1) return true;
    }

    return false;
  }
};
