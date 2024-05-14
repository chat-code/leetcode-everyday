// Date: Mon Jan 17 06:07:11 2022

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

const int N = 20010;
ll d[N][26];

class Solution {
public:
  int countVowelPermutation(int n) {
    memset(d, 0, sizeof d);

    for (auto &c : {'a', 'e', 'i', 'o', 'u'}) d[n][c - 'a'] = 1;
    for (int i = n - 1; i >= 1; --i) {
      ll a1 = d[i + 1][0], e1 = d[i + 1]['e' - 'a'],
        i1 = d[i + 1]['i' - 'a'], o1 = d[i + 1]['o' - 'a'],
        u1 = d[i + 1]['u' - 'a'];

      d[i]['a' - 'a'] = e1;
      d[i]['e' - 'a'] = (a1 + i1) % MOD;
      d[i]['i' - 'a'] = (a1 + e1 + o1 + u1) % MOD;
      d[i]['o' - 'a'] = (i1 + u1) % MOD;
      d[i]['u' - 'a'] = a1;
    }

    ll res {};
    for (auto &c : {'a', 'e', 'i', 'o', 'u'})
      res = (res + d[1][c - 'a']) % MOD;

    return res;
  }
};
