// Date: Wed Oct 27 16:32:37 2021

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

const int N = 30010;
bool d[N];

class Solution {
public:
  bool wordBreak(string s, vector<string>& di) {
    set<string> d1;
    memset(d, false, sizeof d);
    for (auto &x : di) d1.insert(x);

    int n = s.size();
    d[0] = true;

    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= i + 1; ++j) {
        int start = i + 1 - j;
        if (d[start]) {
          if (d1.find(s.substr(start, j)) != d1.end()) {
            d[i + 1] = true;
            break;
          }
        }
      }
    }

    return d[n];
  }
};
