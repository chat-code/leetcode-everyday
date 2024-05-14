// Date: Sun Feb  6 10:46:38 2022

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

class Bitset {
public:
  int sz;
  map<int, int> m;
  bool flag;
  int cnt1, cnt0;

  Bitset(int size) {
    sz = size;
    flag = false;
    cnt1 = 0;
    cnt0 = sz;
    m.clear();
  }

  void fix(int idx) {
    if (flag) {
      unfix1(idx);
      return;
    }

    if (m[idx]) return;
    m[idx] = 1;
    cnt1++;
    cnt0--;
  }

  void fix1(int idx) {
    if (m[idx]) return;
    m[idx] = 1;
    cnt1++;
    cnt0--;
  }

  void unfix(int idx) {
    if (flag) {
      fix1(idx);
      return;
    }

    if (!m[idx]) return;
    m[idx] = 0;
    cnt0++;
    cnt1--;
  }

  void unfix1(int idx) {
    if (!m[idx]) return;
    m[idx] = 0;
    cnt0++;
    cnt1--;
  }

  void flip() {
    flag = !flag;
  }

  bool all() {
    if (flag) {
      return cnt0 == sz;
    } else {
      return cnt1 == sz;
    }
  }

  bool one() {
    if (flag) {
      return cnt0 > 0;
    } else {
      return cnt1 > 0;
    }
  }

  int count() {
    if (flag) return cnt0;
    else return cnt1;
  }

  string toString() {
    string res;
    for (int i = 0; i < sz; ++i) {
      if (flag) {
        if (!m[i]) res += "1";
        else res += "0";
      } else {
        if (m[i]) res += "1";
        else res += "0";
      }
    }
    return res;
  }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
