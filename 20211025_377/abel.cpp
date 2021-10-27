// Date: Wed Oct 27 15:06:18 2021

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

typedef ListNode LN;
typedef LN* LNP;

#endif

const int N = 1010;
unsigned long long d[N];

class Solution {
public:
  int combinationSum4(vector<int>& a, int sum) {
    int n = a.size();
    memset(d, 0, sizeof d);
    d[0] = 1;
    for (int i = 0; i <= sum; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i >= a[j]) d[i] += d[i - a[j]];
      }
    }

    return d[sum];
  }
};
