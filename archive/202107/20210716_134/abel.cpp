// Date: Mon Nov  1 18:27:00 2021

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
  int canCompleteCircuit(vector<int>& g, vector<int>& c) {
    int n = g.size(), sum {};
    VI g1(n, 0);
    for (int i = 0; i < n; ++i) {
      g1[i] = g[i] - c[i];
      sum += g1[i];
    }
    if (sum < 0) return -1;

    for (int i = 0; i < n; ++i) {
      if (g1[i] >= 0) {
        int j = i, cur = g1[i];
        bool flag = true;
        ++j;
        j %= n;
        while (j != i) {
          cur += g1[j];
          if (cur < 0) {
            flag = false;
            break;
          }
          ++j;
          j %= n;
        }

        if (flag) return i;
        if (j < i) return -1;
        i = j - 1;
      }
    }

    return -1;
  }
};
