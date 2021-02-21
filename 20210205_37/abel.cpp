class Solution {
public:
  int col[9][9], row[9][9], b[3][3][9];

  bool dfs(int x, int y, vector<vector<char>> &a) {
    if (y == 9) { ++x; y = 0; }
    if (x == 9) return true;
    if (a[x][y] != '.') return dfs(x, y + 1, a);

    for (int i = 0; i < 9; ++i) {
      if (!col[y][i] && !row[x][i] && !b[x/3][y/3][i]) {
        col[y][i] = row[x][i] = b[x/3][y/3][i] = 1;
        a[x][y] = '1' + i;
        if (dfs(x, y + 1, a)) return true;
        a[x][y] = '.';
        col[y][i] = row[x][i] = b[x/3][y/3][i] = 0;
      }
    }

    return false;
  }

  void solveSudoku(vector<vector<char>>& a) {
    memset(col, 0, sizeof col);
    memset(row, 0, sizeof row);
    memset(b, 0, sizeof b);

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (a[i][j] != '.') {
          int x = a[i][j] - '1';
          col[j][x] = row[i][x] = b[i / 3][j / 3][x] = 1;
        }
      }
    }

    dfs(0, 0, a);
  }
};
