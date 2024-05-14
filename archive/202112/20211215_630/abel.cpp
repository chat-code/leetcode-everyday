// Date: Fri Dec 17 20:07:43 2021

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
  int scheduleCourse(vector<vector<int>>& a) {
    int n = a.size();

    sort(a.begin(), a.end(), [&](const VI &x, const VI &y) {
      return x[1] < y[1];
    });

    priority_queue<int> q;
    int res {}, sum {};

    for (int i = 0; i < n; ++i) {
      int tmp = sum + a[i][0];

      if (tmp > a[i][1]) {
        if (!q.empty() && q.top() > a[i][0]) {
          int x = q.top();
          q.pop();
          q.push(a[i][0]);
          sum -= (x - a[i][0]);
        }
      } else {
        q.push(a[i][0]);
        sum += a[i][0];
      }

      res = max(res, int(q.size()));
    }

    return res;
  }
};
