constexpr int dir[][2] = {{0, +1}, {+1, 0}, {0, -1}, {-1, 0}};

class Solution {
  int facing = 0;
public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int x = 0, y = 0;
    int ma = 0;
    set<pair<int, int>> o;
    for (auto&& obstacle : obstacles) {
      o.insert({obstacle[0], obstacle[1]});
    }
    for (auto cmd : commands) {
      if (cmd < 0) {
        if (cmd == -1) {
          facing = (facing + 5) % 4;
        } else {
          facing = (facing + 3) % 4;
        }
      } else {
        for (int d = 1; d <= cmd; ++d) {
          x += dir[facing][0], y += dir[facing][1];
          if (o.find(make_pair(x, y)) != o.end()) {
            x -= dir[facing][0], y -= dir[facing][1];
            break;
          }
        }
      }
      ma = max(ma, x * x + y * y);
    }
    
    return ma;
  }
};
