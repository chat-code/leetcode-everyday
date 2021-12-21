// Date: Wed Dec 22 00:54:57 2021

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

VI months {
  0, 31, 28, 31, 30, 31,
  30, 31, 31, 30, 31, 30,
  31,
};

class Solution {
public:
  bool leap(int y) {
    return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
  }

  int dayOfYear(string a) {
    int res {};
    string year_s = a.substr(0, 4), month_s = a.substr(5, 2), day_s = a.substr(8, 2);

    int year, month, day;
    stringstream ss1(year_s), ss2(month_s), ss3(day_s);
    ss1 >> year;
    ss2 >> month;
    ss3 >> day;

    res = day;
    for (int i = 1; i < month; ++i) {
      res += months[i];

      if (i == 2 && leap(year)) {
        res++;
      }
    }

    return res;
  }
};
