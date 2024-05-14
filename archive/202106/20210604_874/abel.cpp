int dir[4][2] = {
  {0, 1}, {1, 0},
  {0, -1}, {-1, 0},
};

class Solution {
public:
  using PII = pair<int, int>;

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
      int res = 0, x = 0, y = 0, idx = 0;
      map<PII, int> pos;
      for (auto &x : obstacles) {
        pos[PII(x[0], x[1])] = 1;
      }

      for (auto &v : commands) {
        if (v == -1) {
          idx = (idx + 1) % 4;
        } else if (v == -2) {
          idx = (idx - 1 + 4) % 4;
        } else {
          while (v--) {
            int x1 = x + dir[idx][0], y1 = y + dir[idx][1];
            if (!pos.count(PII(x1, y1))) {
              x = x1; y = y1;
              res = max(res, x * x + y * y);
            } else {
              break;
            }
          }
        }
      }

      return res;
    }
};
