const int N = 20;
int col[N], d1[2*N], d2[2*N];

class Solution {
public:
  int res, n;

  void dfs(int x) {
    if (x == n) {
      ++res; return;
    }

    for (int j = 0; j < n; ++j) {
      if (!col[j] && !d1[j + x] && !d2[j - x + n]) {
        col[j] = d1[j + x] = d2[j - x + n] = 1;
        dfs(x + 1);
        col[j] = d1[j + x] = d2[j - x + n] = 0;
      }
    }
  }

  int totalNQueens(int _n) {
    res = 0;
    memset(col, 0, sizeof col);
    memset(d1, 0, sizeof d1);
    memset(d2, 0, sizeof d2);
    n = _n;

    dfs(0);

    return res;
  }
};
