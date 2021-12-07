// Date: Mon Nov 29 23:08:15 2021

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
  long long countVowels(string a) {
    ll res {};

    unordered_set<char> vowel {'a', 'e', 'i', 'o', 'u'};

    int n = a.size();
    vector<ll> p(n, 0);

    if (vowel.find(a[0]) != vowel.end()) p[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (vowel.find(a[i]) != vowel.end()) {
        p[i] = p[i - 1] + i + 1;
      } else {
        p[i] = p[i - 1];
      }
    }

    for (int i = 0; i < n; ++i) res += p[i];

    return res;
  }
};
