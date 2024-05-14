#include <vector>

using namespace std;
using ll = long long;
const int N = 310;
ll s[N][N], a[N][N];

class Solution {
public:
  int maxSideLength(vector<vector<int>> &_a, int x) {
    int n = _a.size(), m = _a[0].size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        a[i+1][j+1] = _a[i][j];
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
      }
    }

    int l = 0, r = min(m, n), mid;
    while (l < r) {
      mid = (l + r + 1) >> 1;

      bool flag = false;
      ll sum = 0;
      for (int i = 1; i + mid - 1 <= n; ++i) {
        for (int j = 1; j + mid - 1 <= m; ++j) {
          int i1 = i + mid - 1, j1 = j + mid - 1;
          sum = s[i1][j1] + s[i - 1][j - 1] - s[i1][j - 1] - s[i - 1][j1];
          if (sum <= x) { flag = true; break; }
        }
      }

      if (flag) l = mid;
      else r = mid - 1;
    }

    return l;
  }
};
