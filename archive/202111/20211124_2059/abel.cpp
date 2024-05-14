// Date: Mon Nov 29 11:31:25 2021

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

const int N = 1010;
int dis[N];
bool st[N];

class Solution {
public:
  int minimumOperations(vector<int>& a, int start, int goal) {
    int n = a.size();

    memset(dis, 0x3f, sizeof dis);
    memset(st, false, sizeof st);
    dis[start] = 0;
    st[start] = true;

    queue<ll> q;
    q.push(start);

    while (!q.empty()) {
      ll t = q.front();
      q.pop();

      st[t] = false;
      int base = dis[t];

      if (t == goal) return base;

      for (int i = 0; i < n; ++i) {
        for (ll ne : {t + a[i], t - a[i], t ^ a[i]}) {
          if (ne == goal) return base + 1;

          if (!(ne >= 0 && ne <= 1000)) continue;

          int tmp = base + 1;
          if (tmp < dis[ne]) {
            dis[ne] = tmp;
            if (!st[ne]) {
              st[ne] = true;
              q.push(ne);
            }
          }
        }
      }
    }

    return -1;
  }
};
