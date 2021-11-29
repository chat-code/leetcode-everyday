// Date: Sun Nov 21 10:56:20 2021

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

class RangeFreqQuery {
public:
  unordered_map<int, VI> m;
  int n;

  RangeFreqQuery(vector<int>& arr) {
    n = arr.size();
    for (int i = 0; i < n; ++i) {
      m[arr[i]].push_back(i);
    }
  }

  int query(int left, int right, int value) {
    VI &v = m[value];
    if (v.size() == 0) return 0;

    int l = 0, r = v.size() - 1, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (v[mid] >= left) r = mid;
      else l = mid + 1;
    }

    if (v[r] < left) return 0;
    int l1 = r;

    l = 0, r = v.size() - 1;
    while (l < r) {
      mid = (l + r + 1) / 2;
      if (v[mid] <= right) l = mid;
      else r = mid - 1;
    }
    if (v[l] > right) return 0;
    int r1 = l;

    return r1 - l1 + 1;
  }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
