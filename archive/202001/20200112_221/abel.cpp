// Date: Wed Oct 13 11:26:47 2021

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

const int N = 310;
int s[N][N], d[N][N];

class Solution {
public:
  int maximalSquareV1(vector<vector<char>>& _a) {
    int n = _a.size(), m = _a[0].size();

    vector<VI> a(n, VI(m, 0));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        a[i][j] = _a[i][j] - '0';

    memset(s, 0, sizeof s);
    memset(d, 0, sizeof d);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int x = i + 1, y = j + 1;
        s[x][y] = a[i][j] + s[x - 1][y] + s[x][y - 1] - s[x - 1][y - 1];
        d[i][j] = a[i][j];
      }
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        for (int k = 0; k < i && k < j; ++k) {
          int i1 = i - k, j1 = j - k;
          int ar = s[i][j] - s[i][j1 - 1] - s[i1 - 1][j] + s[i1 - 1][j1 - 1];
          if (ar == (k + 1) * (k + 1)) {
            d[i][j] = max(d[i][j], ar);
          }
        }
      }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        res = max(res, d[i][j]);

    return res;
  }

  int maximalSquare(vector<vector<char>>& _a) {
    int n = _a.size(), m = _a[0].size();

    vector<VI> a(n, VI(m, 0));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        a[i][j] = _a[i][j] - '0';

    memset(d, 0, sizeof d);

    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j]) {
          if (i && j) d[i][j] = min(d[i - 1][j],
                                    min(d[i][j - 1], d[i - 1][j - 1])) + 1;
          else d[i][j] = 1;

          res = max(res, d[i][j]);
        }
      }
    }

    return res * res;
  }
};
