// Date: Fri Dec  3 23:00:11 2021

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
  bool wordPattern(string p, string s) {
    stringstream ss(s);
    vector<string> a;

    string tmp;

    while (ss >> tmp) {
      a.push_back(tmp);
    }

    int n = p.size();
    if (n != a.size()) return false;

    map<char, string> m;
    set<string> values;

    for (int i = 0; i < n; ++i) {
      if (m.find(p[i]) == m.end()) {
        if (values.find(a[i]) == values.end()) {
          m[p[i]] = a[i];
          values.insert(a[i]);
        } else {
          return false;
        }
      } else {
        if (m[p[i]] != a[i]) return false;
      }
    }

    return true;
  }
};
