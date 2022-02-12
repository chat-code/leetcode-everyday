// Date: Fri Dec  3 22:54:01 2021

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
  vector<string> findRelativeRanks(vector<int>& a) {
    int n = a.size();
    VI b = a;
    map<int, string> m;

    sort(b.begin(), b.end(), greater<int>());

    vector<string> name {
      "Gold Medal", "Silver Medal", "Bronze Medal",
    };

    for (int i = 0; i < n; ++i) {
      if (i < 3) {
        m[b[i]] = name[i];
      } else {
        m[b[i]] = to_string(i + 1);
      }
    }

    vector<string> res;
    for (int i = 0; i < n; ++i) {
      res.push_back(m[a[i]]);
    }
    return res;
  }
};
