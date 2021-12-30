// Date: Thu Dec 30 10:28:31 2021

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

const int N = 30010;
char s[N], p[N];
int ne[N];

class Solution {
public:
  int repeatedStringMatch(string a, string b) {
    int n = a.size(), m = b.size(), res = 1;

    stringstream b1(b);
    b1 >> (p + 1);
    memset(ne, 0, sizeof ne);

    string a1 = a;
    while (a1.size() < m) {
      a1 += a;
      res++;
    }

    a1 += a;
    res++;

    stringstream a2(a1);
    a2 >> (s + 1);
    n = a1.size();

    int i, j;
    for (i = 2, j = 0; i <= m; ++i) {
      while (j && p[i] != p[j + 1]) j = ne[j];
      if (p[i] == p[j + 1]) ++j;
      ne[i] = j;
    }

    for (i = 1, j = 0; i <= n; ++i) {
      while (j && s[i] != p[j + 1]) j = ne[j];
      if (s[i] == p[j + 1]) ++j;
      if (j == m) {
        if (n - i >= a.size()) res--;
        return res;
      }
    }

    return -1;
  }
};
