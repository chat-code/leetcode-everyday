// Date: Tue Dec  7 10:44:17 2021

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

VI a;

class Solution {
public:
  struct Node {
    int i, j;

    Node(int i_ = 0, int j_ = 0)
      :i(i_), j(j_) {}

    bool operator< (const Node & o) const {
      return a[i] * 1.0 / a[j] > a[o.i] * 1.0 / a[o.j];
    }
  };

  vector<int> kthSmallestPrimeFraction(vector<int>& a_, int k) {
    a = a_;

    int n = a.size();
    VI res(2, 0);

    priority_queue<Node> q;
    for (int i = 1; i < n; ++i) q.push(Node(0, i));

    while (k--) {
      auto t = q.top();
      q.pop();

      if (!k) {
        res[0] = a[t.i];
        res[1] = a[t.j];
        break;
      }

      int i = t.i, j = t.j;
      if (i + 1 < j) {
        q.push(Node(i + 1, j));
      }
    }

    return res;
  }
};
