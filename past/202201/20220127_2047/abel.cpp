// Date: Thu Jan 27 10:12:07 2022

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
  bool check(const string &s) {
    int n = s.size();
    int dash_cnt {}, ncnt {};

    for (int i = 0; i < n; ++i) {
      if (islower(s[i])) continue;
      if (s[i] == '-') {
        if (i == 0 || i == n) return false;
        if (!islower(s[i - 1]) || !islower(s[i + 1])) return false;

        dash_cnt++;
      } else if (s[i] == ',' || s[i] == '.' || s[i] == '!') {
        if (i != n - 1) return false;
        ncnt++;
      } else
        return false;
    }

    if (dash_cnt > 1 || ncnt > 1) return false;

    return true;
  }

  int countValidWords(string a) {
    int res {};
    stringstream ss(a);
    string s;

    while (ss >> s) {
      if (check(s)) res++;
    }

    return res;
  }
};
