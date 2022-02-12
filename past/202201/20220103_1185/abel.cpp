// Date: Mon Jan  3 23:50:06 2022

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

class Solution {
public:
  const vector<string> weeks {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
  };
  const VI months {
    0, 31, 28, 31, 30, 31,
    30, 31, 31, 30, 31,
    30, 31,
  };

  bool is_leap(int n) {
    return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
  }

  string dayOfTheWeek(int day, int month, int year) {
    int days = 4;
    for (int i = 1971; i <= year - 1; ++i) {
      if (is_leap(i)) days += 366;
      else days += 365;
    }

    for (int i = 1; i <= month - 1; ++i) {
      days += months[i];
      if (is_leap(year) && i == 2) days++;
    }

    days += day;

    return weeks[days % 7];
  }
};
