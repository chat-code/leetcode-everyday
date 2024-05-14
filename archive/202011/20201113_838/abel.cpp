// Date: Mon Feb 21 19:00:52 2022

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
  string pushDominoes(string a) {
    int n = a.size();
    VI ts(n, INF);
    string b = a;

    for (int i = 0; i < n; ++i) {
      if (a[i] == '.') continue;
      else if (a[i] == 'R') {
        ts[i] = 0;
        b[i] = 'R';
        int cur = 1;
        int j = i + 1;
        while (j < n && a[j] == '.') {
          b[j] = 'R';
          ts[j] = cur++;
          ++j;
        }
      } else {
        ts[i] = 0;
        b[i] = 'L';
        int cur = 1;
        int j = i - 1;
        while (j >= 0 && a[j] == '.' && cur <= ts[j]) {
          if (cur == ts[j]) {
            b[j] = '.';
            break;
          }
          b[j] = 'L';
          ts[j] = cur++;
          --j;
        }
      }
    }

    return b;
  }
};
