// Date: Mon Dec  6 13:05:26 2021

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

struct Job {
  int s, t;
  int p;

  Job(int s_, int t_, int p_)
    :s(s_), t(t_), p(p_) {}
  Job()
    :s(0), t(0), p(0) {}

  bool operator<(const Job &o) const {
    if (t != o.t) return t < o.t;
    return s < o.s;
  }
};

class Solution {
public:
  int jobScheduling(vector<int>& s1, vector<int>& e1, vector<int>& p1) {
    int n = s1.size();
    vector<Job> a(n);
    for (int i = 0; i < n; ++i) a[i] = Job(s1[i], e1[i], p1[i]);

    sort(a.begin(), a.end());

    int res = a[0].p;
    VI d(n, 0);
    d[0] = a[0].p;

    for (int i = 1; i < n; ++i) {
      int start = a[i].s;

      int l = 0, r = i - 1, mid;
      while (l < r) {
        mid = (l + r + 1) / 2;
        if (a[mid].t <= start) l = mid;
        else r = mid - 1;
      }

      if (a[l].t <= start) {
        d[i] = max(a[i].p + d[l], d[i - 1]);
      } else {
        d[i] = max(a[i].p, d[i - 1]);
      }
    }

    for (int i = 0; i < n; ++i) res = max(res, d[i]);

    return res;
  }
};
