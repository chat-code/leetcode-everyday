#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

const int N = 10010, INF = 0x3f3f3f3f;
int d[N], d1[20][N];

class Solution {
public:
  int coinChange(vector<int>& a, int amount) {
    int n = a.size();
    int V = amount;

    memset(d1, INF, sizeof d1);
    for (int i = 0; i < n; ++i) {
      d1[i][0] = 0;
      for (int j = 0; j <= V; ++j) {
        if (i) {
          if (j >= a[i]) d1[i][j] = min(d1[i - 1][j], d1[i][j - a[i]] + 1);
          else d1[i][j] = d1[i - 1][j];
        } else {
          if (j >= a[i]) d1[i][j] = d1[i][j - a[i]] + 1;
        }
      }
    }

    return d1[n-1][V] >= INF ? -1 : d1[n-1][V];
  }

  int coinChangeD1(vector<int>& a, int amount) {
    int n = a.size();
    int V = amount;

    memset(d, INF, sizeof d);
    d[0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = a[i]; j <= V; ++j) {
        d[j] = min(d[j], d[j - a[i]] + 1);
      }
    }

    return d[V] >= INF ? -1 : d[V];
  }
};
