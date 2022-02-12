// Date: Sun Jan 30 10:52:25 2022

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

const int N = 20010;
ull p[N], h[N];

class Solution {
public:
  string subStrHash(string s, int power, int modulo, int k, int hashValue) {
    int n = s.size();

    memset(p, 0, sizeof p);
    p[0] = 1;

    for (int i = 1; i <= n; ++i) {
      int c = s[i - 1] - 'a' + 1;
      p[i] = (p[i - 1] * power) % modulo;
    }

    ull val = 0, idx = -1;
    for (int i = n - k; i < n; ++i) {
      int c = s[i] - 'a' + 1;
      val = (c * p[i - (n - k)] + val) % modulo;
    }
    if (val == hashValue) idx = n - k;

    for (int i = n - k - 1; i >= 0; --i) {
      int c = s[i] - 'a' + 1, c1 = s[i + k] - 'a' + 1;
      val = (val - c1 * p[k - 1] % modulo + modulo);
      val = (val * power + c) % modulo;

      if (val == hashValue) idx = i;
    }

    // cout << "idx = " << idx << endl;
    return s.substr(idx, k);
  }
};
