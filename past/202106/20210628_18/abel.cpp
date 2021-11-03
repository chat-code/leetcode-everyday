// Date: Wed Nov  3 11:05:48 2021

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
  vector<vector<int>> fourSum(vector<int>& a, int ta) {
    int n = a.size();
    vector<VI> res;

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
      if (i && a[i] == a[i - 1]) continue;
      for (int j = i + 1; j < n; ++j) {
        if (j > i + 1 && a[j] == a[j - 1]) continue;

        int sum = a[i] + a[j];
        int t = ta - sum;
        int k = j + 1, r = n - 1;
        while (k < r) {
          int tmp = a[k] + a[r];
          if (tmp == t) {
            VI v = VI{a[i], a[j], a[k], a[r]};
            res.push_back(v);
            ++k; --r;
            while (k < r && a[k] == a[k - 1]) ++k;
          } else if (tmp > t) --r;
          else ++k;
        }
      }
    }

    return res;
  }
};
