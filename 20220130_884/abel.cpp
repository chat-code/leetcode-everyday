// Date: Sun Jan 30 10:29:17 2022

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
  vector<string> uncommonFromSentences(string s1, string s2) {
    stringstream ss1(s1), ss2(s2);
    map<string, int> m1, m2;

    string x;
    while (ss1 >> x) {
      m1[x]++;
    }
    while (ss2 >> x) m2[x]++;

    vector<string> res;
    for (auto &p : m1) {
      x = p.first;
      int cnt = p.second;

      if (cnt == 1 && m2.find(x) == m2.end()) res.push_back(x);
    }

    for (auto &p : m2) {
      x = p.first;
      int cnt = p.second;

      if (cnt == 1 && m1.find(x) == m1.end()) res.push_back(x);
    }

    return res;
  }
};
