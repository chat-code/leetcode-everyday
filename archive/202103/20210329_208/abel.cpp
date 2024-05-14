// Date: Wed Nov 17 00:44:00 2021

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

const int N = 2010 * 26;
int son[N][26], cnt[N], idx;

class Trie {
public:
  Trie() {
    idx = 0;
    memset(cnt, 0, sizeof cnt);
    memset(son, 0, sizeof son);
  }

  void insert(string word) {
    int p = 0;
    for (auto &c : word) {
      int u = c - 'a';
      if (!son[p][u]) son[p][u] = ++idx;
      p = son[p][u];
    }

    cnt[p]++;
  }

  bool search(string word) {
    int p = 0;
    for (auto &c : word) {
      int u = c - 'a';
      if (!son[p][u]) return false;
      p = son[p][u];
    }

    return cnt[p] > 0;
  }

  bool startsWith(string prefix) {
    int p = 0;
    for (auto &c : prefix) {
      int u = c - 'a';
      if (!son[p][u]) return false;
      p = son[p][u];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
