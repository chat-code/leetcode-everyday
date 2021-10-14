class Solution {
public:
  bool check(int m[3][3], int x) {
    bool mark = false;
    for (int i = 0; i < 3; ++i) {
      mark = true;
      for (int j = 0; j < 3; ++j) {
        if (m[i][j] != x) {
          mark = false;
          break;
        }
      }
      if (mark) return true;
    }

    for (int j = 0; j < 3; ++j) {
      mark = true;
      for (int i = 0; i < 3; ++i) {
        if (m[i][j] != x) {
          mark = false;
          break;
        }
      }
      if (mark) return true;
    }

    mark = true;
    for (int i = 0; i < 3; ++i) {
      if (m[i][i] != x) {
        mark = false;
        break;
      }
    }
    if (mark) return true;

    mark = true;
    for (int i = 0; i < 3; ++i) {
      if (m[i][2-i] != x) {
        mark = false;
        break;
      }
    }

    return mark;
  }

  string tictactoe(vector<vector<int>>& a) {
    int m[3][3] {};
    for (int i = 0; i < a.size(); ++i) {
      int x = a[i][0], y = a[i][1];
      if (i & 1) {
        m[x][y] = 2;
      } else {
        m[x][y] = 1;
      }
    }

    int rem {};
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (m[i][j] == 0) {
          rem++;
          break;
        }
    if (check(m, 1)) return "A";
    else if (check(m, 2)) return "B";
    else if (rem) return "Pending";
    return "Draw";
  }
};
