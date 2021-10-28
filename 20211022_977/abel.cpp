// Date: Thu Oct 28 10:20:40 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

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

typedef ListNode LN;
typedef LN* LNP;
typedef TreeNode TN;
typedef TN* TNP;

class Solution {
public:
  vector<int> sortedSquares(vector<int>& a) {
    VI res;
    int n = a.size();

    int l = 0, r = n - 1, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (a[mid] >= 0) r = mid;
      else l = mid + 1;
    }
    if (a[r] >= 0) {
      int i = r, j = r - 1;
      while (i < n || j >= 0) {
        if (i < n && j >= 0) {
          int x = abs(a[i]), y = abs(a[j]);
          if (x <= y) {
            res.push_back(x * x); ++i;
          } else {
            res.push_back(y * y); --j;
          }
        } else if (i < n) {
          res.push_back(a[i] * a[i]); ++i;
        } else if (j >= 0) {
          res.push_back(a[j] * a[j]); --j;
        }
      }
    } else {
      for (int i = n - 1; i >= 0; --i) res.push_back(a[i] * a[i]);
      return res;
    }

    return res;
  }
};
