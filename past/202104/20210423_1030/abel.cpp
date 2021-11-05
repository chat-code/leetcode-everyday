using VI = vector<int>;
using PII = pair<int, int>;
const int N = 110;
int st[N][N];

const int dir[4][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
};

class Solution {
public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    memset(st, 0, sizeof st);
    PII x = PII(r0, c0);
    vector<VI> res;

    st[r0][c0] = 1;
    queue<PII> q({x});

    while (!q.empty()) {
      x = q.front();
      q.pop();

      int x1 = x.first, y1 = x.second;
      res.push_back({x1, y1});

      for (int i = 0; i < 4; ++i) {
        int x2 = x1 + dir[i][0], y2 = y1 + dir[i][1];
        if (x2 >= 0 && x2 < R && y2 >= 0 && y2 < C && !st[x2][y2]) {
          st[x2][y2] = 1;
          q.push({x2, y2});
        }
      }
    }

    return res;
  }
};
