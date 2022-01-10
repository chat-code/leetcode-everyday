// Date: Tue Jan 11 07:05:54 2022

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
  int n;
  PII start, end;
  set<PII> blocked;

  bool bfs(PII st, PII en) {
    queue<PII> q;
    q.push(st);

    set<PII> vis;
    vis.insert(st);

    while (!q.empty()) {
      auto t = q.front();
      q.pop();

      int x = t.first, y = t.second, x1, y1;

      if (PII(x, y) == en) return true;

      for (int i = 0; i < 4; ++i) {
        x1 = x + dir[i][0];
        y1 = y + dir[i][1];
        auto ne = PII(x1, y1);

        if (x1 == en.first && y1 == en.second) return true;

        if (x1 >= 0 && x1 < 1e6 && y1 >= 0 && y1 < 1e6 && vis.find(ne) == vis.end()
            && blocked.find(ne) == blocked.end()) {
          q.push(ne);
          vis.insert(ne);

          if (vis.size() > n * (n - 1) / 2) return true;
        }
      }
    }

    return false;
  }

  bool isEscapePossible(vector<vector<int>>& _blocked, vector<int>& source, vector<int>& target) {
    n = _blocked.size();

    if (n == 0 || n == 1) return true;

    start = PII(source[0], source[1]);
    end = PII(target[0], target[1]);
    for (auto &v : _blocked) {
      blocked.insert(PII(v[0], v[1]));
    }

    return bfs(start, end) && bfs(end, start);
  }
};
