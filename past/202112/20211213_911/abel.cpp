// Date: Fri Dec 17 20:59:59 2021

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

const int N = 5010;
int cnt[N];
PII a[N];

class TopVotedCandidate {
public:
  int n;

  TopVotedCandidate(vector<int>& b, vector<int>& c) {
    n = b.size();
    memset(cnt, 0, sizeof cnt);
    int cur = -1;

    for (int i = 0; i < n; ++i) {
      int p = b[i], t = c[i];
      cnt[p]++;

      if (cur <= cnt[p]) {
        cur = cnt[p];
        a[i] = PII(p, t);
      } else {
        a[i] = a[i - 1];
      }
    }
  }

  int q(int t) {
    int l = 0, r = n - 1, mid;

    while (l < r) {
      mid = (l + r + 1) / 2;
      if (a[mid].second <= t) l = mid;
      else r = mid - 1;
    }

    return a[l].first;
  }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
