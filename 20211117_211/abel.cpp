// Date: Wed Nov 17 01:13:15 2021

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

const int N = 510 * 5000;
static int cnt[N], son[N][26], idx;

class WordDictionary {
public:
  WordDictionary() {
    idx = 0;
    memset(son, 0, sizeof son);
    memset(cnt, 0, sizeof cnt);
  }

  void addWord(string word) {
    int p = 0;
    for (auto &c : word) {
      int u = c - 'a';
      if (!son[p][u]) son[p][u] = ++idx;
      p = son[p][u];
    }

    ++cnt[p];
  }

  bool dfs(int p, string &w, int idx) {
    for (int i = idx; i < w.size(); ++i) {
      if (w[i] == '.') {
        for (int j = 0; j < 26; ++j) {
          if (son[p][j]) {
            if (dfs(son[p][j], w, i + 1))
              return true;
          }
        }
        return false;
      } else {
        int u = w[i] - 'a';
        if (!son[p][u]) return false;
        p = son[p][u];
      }
    }

    return cnt[p] > 0;
  }

  bool search(string word) {
    return dfs(0, word, 0);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
