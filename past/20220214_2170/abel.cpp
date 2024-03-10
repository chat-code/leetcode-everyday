// Date: Fri Feb 18 19:31:50 2022

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
  vector<PII> top2(map<int, int> &m) {
    vector<PII> a;
    for (auto &p : m) {
      a.push_back(PII(p.second, p.first));
    }

    sort(a.begin(), a.end(), greater<PII>());

    int n = a.size();
    vector<PII> res;

    res.push_back(a[0]);
    if (n > 1) res.push_back(a[1]);

    return res;
  }

  int minimumOperations(vector<int>& a) {
    map<int, int> even, odd;
    int n = a.size();
    if (n == 1) return 0;

    for (int i = 0; i < n; ++i) {
      if (i & 1) odd[a[i]]++;
      else even[a[i]]++;
    }

    auto evens = top2(even), odds = top2(odd);
    if (evens[0].second != odds[0].second) {
      return n - evens[0].first - odds[0].first;
    }
    int sz1 = evens.size(), sz2 = odds.size(), tmp = max(evens[0].first, odds[0].first);

    if (sz1 > 1) tmp = max(tmp, evens[1].first + odds[0].first);
    if (sz2 > 1) tmp = max(tmp, evens[0].first + odds[1].first);

    return n - tmp;
  }
};
