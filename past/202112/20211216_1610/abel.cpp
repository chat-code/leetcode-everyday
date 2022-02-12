// Date: Fri Dec 17 15:51:56 2021

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

const double PI = 3.1415926;

class Solution {
public:
  int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
    double x0 = location[0], y0 = location[1];
    vector<double> a;
    int cnt = 0;

    for (int i = 0; i < points.size(); ++i) {
      double x = points[i][0], y = points[i][1], dx = x - x0, dy = y - y0;
      if (fabs(dx) < eps && fabs(dy) < eps) {
        cnt++;
        continue;
      }

      double tmp = atan2(dy, dx);
      a.push_back(tmp);
      a.push_back(tmp + 2 * PI);
    }

    sort(a.begin(), a.end());

    int n = a.size();
    double ag = PI / 180 * angle;
    int res = 0;

    for (int i = 0, j = 0; j < n; ++j) {
      while (a[j] - a[i] - ag > eps) {
        ++i;
      }

      res = max(res, j - i + 1);
    }

    res += cnt;

    return res;
  }
};
