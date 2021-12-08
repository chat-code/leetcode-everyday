// Date: Thu Dec  9 00:39:38 2021

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

class MyCircularQueue {
public:
  vector<int> a;
  int n, hh, tt, size;

  MyCircularQueue(int k)
    :hh(0), tt(-1), n(k), size(0) {
    a = VI (n, 0);
  }

  bool enQueue(int value) {
    if (isFull()) return false;

    size++;
    ++tt;
    if (tt == n) tt = 0;

    a[tt] = value;

    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;

    size--;
    ++hh;
    if (hh == n) hh = 0;

    return true;
  }

  int Front() {
    if (isEmpty()) return -1;

    return a[hh];
  }

  int Rear() {
    if (isEmpty()) return -1;

    return a[tt];
  }

  bool isEmpty() {
    return size == 0;
  }

  bool isFull() {
    return size == n;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
