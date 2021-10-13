// Date: Wed Oct 13 14:56:25 2021

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


class Solution {
public:
  string longestPalindrome(string s) {
    int res = 1, n = s.size(), pos = 0;

    for (int i = 1; i < n - 1; ++i) {
      int cur = 1;
      for (int j = i - 1, k = i + 1; j >= 0 && k < n; --j, ++k) {
        if (s[j] == s[k]) {
          cur += 2;
          if (cur > res) {
            res = cur;
            pos = j;
          }
        }
        else {
          break;
        }
      }
    }

    for (int i = 0; i < n - 1; ++i) {
      int cur = 0;
      for (int j = i, k = i + 1; j >= 0 && k < n; --j, ++k) {
        if (s[j] == s[k]) {
          cur += 2;
          if (cur > res) {
            res = cur;
            pos = j;
          }
        }
        else {
          break;
        }
      }
    }
    return s.substr(pos, res);
  }
};
