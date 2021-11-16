// Date: Tue Nov 16 10:45:21 2021

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

struct Node {
  int ts, cnt;
  int key, value;

  Node(int k, int v, int _ts, int _cnt)
    :key(k), value(v), ts(_ts), cnt(_cnt) {}

  bool operator< (const Node& r) const {
    if (cnt != r.cnt) return cnt < r.cnt;
    else return ts < r.ts;
  }
};

class LFUCache {
public:
  int cap, ts;
  set<Node> s;
  map<int, set<Node>::iterator> m;

  LFUCache(int capacity) {
    cap = capacity;
    s.clear();
    m.clear();
    ts = 0;
  }

  int get(int key) {
    if (!cap) return -1;

    if (m.find(key) == m.end()) return -1;
    ++ts;
    auto it = m[key];
    auto x = *it;
    s.erase(it);

    x.ts = ts;
    int res = x.value;
    x.cnt++;
    auto resi = s.insert(x);
    m[key] = resi.first;

    return res;
  }

  void put(int key, int value) {
    if (!cap) return;

    ++ts;

    if (m.find(key) == m.end()) {
      if (m.size() == cap) {
        auto it = s.begin();
        int k = it->key;
        m.erase(k);
        s.erase(it);
      }

      Node x(key, value, ts, 1);
      auto resi = s.insert(x);
      m[key] = resi.first;
    } else {
      auto it = m[key];
      auto x = *it;
      s.erase(it);

      x.value = value;
      x.ts = ts;
      x.cnt++;
      auto resi = s.insert(x);
      m[key] = resi.first;
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
