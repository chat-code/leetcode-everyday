// Date: Wed Nov  3 23:13:56 2021

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

const int N = 100010;
int stk[N];

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& a) {
    int n = a.size(), tt = 0;
    VI res;
    for (int i = n - 1; i >= 0; --i) {
      if (!tt) {
        res.push_back(0);
        stk[++tt] = i;
      } else {
        while (tt && a[stk[tt]] <= a[i]) --tt;
        if (!tt) {
          res.push_back(0);
        } else {
          res.push_back(stk[tt] - i);
        }
        stk[++tt] = i;
      }
    }

    reverse(res.begin(), res.end());

    return res;
  }
};
