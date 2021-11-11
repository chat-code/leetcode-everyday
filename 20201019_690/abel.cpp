// Date: Thu Nov 11 18:43:17 2021

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

/*
// Definition for Employee.
class Employee {
public:
int id;
int importance;
vector<int> subordinates;
};
*/

const int N = 2010, M = 4010;
int n, m, h[N], st[N], w[N];
int idx, e[M], ne[M];


void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(st, 0, sizeof st);
}

void Add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
  int res;

  void dfs(int id) {
    if (st[id]) return;

    st[id] = 1;
    res += w[id];

    for (int i = h[id]; i != -1; i = ne[i]) {
      int j = e[i];
      if (!st[j]) {
        dfs(j);
      }
    }
  }

  int getImportance(vector<Employee*> a, int id) {
    Init();
    res = 0;

    for (auto &e : a) {
      int i = e->id, x = e->importance;
      w[i] = x;
      for (auto &f : e->subordinates) {
        Add(i, f);
      }
    }

    dfs(id);

    return res;
  }
};
