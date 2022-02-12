// Date: Wed Jan 26 22:52:11 2022

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

class DetectSquares {
public:
  map<int, map<int, int>> m;

  DetectSquares() {
    m.clear();
  }

  void add(vector<int> point) {
    int x = point[0], y = point[1];
    m[x][y]++;
  }

  int count(vector<int> point) {
    int x = point[0], y = point[1];
    if (m.find(x) == m.end()) return 0;

    int res {};
    for (auto &p : m[x]) {
      int y1 = p.first, c1 = p.second;

      if (y1 == y) continue;
      int delta = y1 - y;
      int x1 = x + delta;
      int c2 = m[x1][y], c3 = m[x1][y1];
      res += c1 * c2 * c3;

      x1 = x - delta;
      c2 = m[x1][y], c3 = m[x1][y1];
      res += c1 * c2 * c3;
    }

    return res;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

