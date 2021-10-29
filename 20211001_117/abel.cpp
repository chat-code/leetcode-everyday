// Date: Fri Oct 29 10:55:06 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

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

typedef ListNode LN;
typedef LN* LNP;
typedef TreeNode TN;
typedef TN* TNP;

/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;

Node() : val(0), left(NULL), right(NULL), next(NULL) {}

Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

Node(int _val, Node* _left, Node* _right, Node* _next)
: val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  using PNI = pair<Node*, int>;

  Node* connect(Node* ro) {
    if (!ro) return ro;

    queue<PNI> que;
    int cur = 1;
    que.push({ro, cur});
    vector<Node*> tmp;

    while (!que.empty()) {
      auto t = que.front(); que.pop();
      auto node = t.first;
      int level = t.second;

      if (level != cur) {
        cur = level;

        for (int i = 1; i < tmp.size(); ++i) {
          tmp[i - 1]->next = tmp[i];
        }

        tmp.clear();
        tmp.push_back(node);
      } else {
        tmp.push_back(node);
      }

      if (node->left) que.push({node->left, level + 1});
      if (node->right) que.push({node->right, level + 1});
    }

    if (!tmp.empty()) {
      for (int i = 1; i < tmp.size(); ++i) {
        tmp[i - 1]->next = tmp[i];
      }
    }

    return ro;
  }
};
