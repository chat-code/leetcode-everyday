class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; ++i) {
      int r = m;
      for (int j = m - 1; j >= 0; --j) {
        if (a[i][j] == '*') r = j;
        else if (a[i][j] == '#') {
          if (j + 1 == r) {
            r = j;
          } else {
            a[i][--r] = '#';
            a[i][j] = '.';
          }
        }
      }
    }

    vector<vector<char>> res(m, vector<char>(n, '0'));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
        res[j][n-1-i] = a[i][j];
      }
    }

    return res;
  }
};
