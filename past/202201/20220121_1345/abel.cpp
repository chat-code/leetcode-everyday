// Date: Fri Jan 21 08:37:20 2022

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
  int minJumps(vector<int>& a) {
    int n = a.size();

    unordered_map<int, VI> m;
    for (int i = 0; i < n; ++i) {
      m[a[i]].push_back(i);
    }

    unordered_set<int> visv;

    int i = 0, step = 0;
    queue<PII> q;
    q.push({i, step});

    unordered_set<int> vis;
    vis.insert(i);

    int res = 0;

    while (!q.empty()) {
      auto t = q.front(); q.pop();
      i = t.first; step = t.second;
      if (i == n - 1) {
        res = step;
        break;
      }

      int j = i + 1;
      if (vis.find(j) == vis.end() && j >= 0 && j < n) {
        vis.insert(j);
        q.push({j, step + 1});
      }

      j = i - 1;
      if (vis.find(j) == vis.end() && j >= 0 && j < n) {
        vis.insert(j);
        q.push({j, step + 1});
      }

      if (visv.find(a[i]) == visv.end()) {
        for (auto &j : m[a[i]]) {
          if (vis.find(j) == vis.end()) {
            vis.insert(j);
            q.push({j, step + 1});
          }
        }
      }

      visv.insert(a[i]);
    }

    return res;
  }
};
