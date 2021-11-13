// Date: Sat Nov 13 10:37:58 2021

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
  unordered_set<string> dead;
  unordered_set<string> vis;

  int openLock(vector<string>& deadends, string target) {
    dead.clear();

    for (auto &s : deadends) dead.insert(s);
    string cur = "0000";
    int step = 0;
    queue<pair<string, int>> q;
    vis.clear();

    vis.insert(cur);

    q.push({cur, step});

    while (!q.empty()) {
      auto t = q.front();
      q.pop();

      cur = t.first;
      step = t.second;

      if (dead.find(cur) != dead.end()) continue;

      if (cur == target) {
        return step;
      }

      string tmp;
      for (int i = 0; i < 4; ++i) {
        tmp = cur;
        if (tmp[i] < '9') tmp[i]++;
        else if (tmp[i] == '9') tmp[i] = '0';
        if (dead.find(tmp) == dead.end() && vis.find(tmp) == vis.end()) {
          q.push({tmp, step + 1});
          vis.insert(tmp);
        }

        tmp = cur;
        if (tmp[i] > '0') tmp[i]--;
        else if (tmp[i] == '0') tmp[i] = '9';
        if (dead.find(tmp) == dead.end() && vis.find(tmp) == vis.end()) {
          q.push({tmp, step + 1});
          vis.insert(tmp);
        }
      }
    }

    return -1;
  }
};
