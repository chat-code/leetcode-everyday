// Date: Mon Dec 20 09:44:45 2021

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

const int N = 1010;
int a[N], b[N];

class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    for (auto &v : trust) {
      a[v[1]]++;
      b[v[0]]++;
    }

    int cnt {}, res = -1;

    for (int i = 1; i <= n; ++i) {
      if (a[i] == n - 1) {
        cnt++;
        res = i;
      }
      if (cnt > 1) return -1;
    }

    if (res != -1 && b[res] > 0) return -1;

    return res;
  }
};
