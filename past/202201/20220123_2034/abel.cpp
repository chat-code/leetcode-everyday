// Date: Sun Jan 23 20:58:57 2022

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

class StockPrice {
public:
  set<int> prices;
  unordered_map<int, int> m;
  int current_ts;
  unordered_map<int, int> cnt;

  StockPrice() {
    current_ts = 0;
    prices.clear();
    m.clear();
  }

  void update(int timestamp, int price) {
    if (m.find(timestamp) == m.end()) {
      m[timestamp] = price;
      prices.insert(price);
      cnt[price]++;
    } else {
      int old = m[timestamp];
      cnt[old]--;

      if (cnt[old] == 0) {
        prices.erase(old);
      }

      m[timestamp] = price;
      prices.insert(price);
      cnt[price]++;
    }

    current_ts = max(current_ts, timestamp);
  }

  int current() {
    return m[current_ts];
  }

  int maximum() {
    return *prices.rbegin();
  }

  int minimum() {
    return *prices.begin();
  }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
