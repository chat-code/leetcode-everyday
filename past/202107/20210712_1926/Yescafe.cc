class Solution {
private:
  struct P {
    int x, y;
    P(int x_, int y_) : x(x_), y(y_) {}
  };
  static constexpr int dir[][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int sx = entrance.front(), sy = entrance.back();
    const auto xx = maze.size(), yy = maze[0].size();
    vector<vector<bool>> vis(xx, vector<bool>(yy, false));
    
    deque<P> dq;
    dq.push_back({sx, sy});
    vis[sx][sy] = true;
    
    int depth = 0;
    while (!dq.empty()) {
      int sz = dq.size();
      while (sz--) {
        auto& top = dq.front();
        for (int d = 0; d < 4; ++d) {
          int nx = top.x + dir[d][0];
          int ny = top.y + dir[d][1];
          // cout << top.x << " " << top.y << " " << nx << " " << ny << endl;
          if ((top.x != sx || top.y != sy) && (nx < 0 || nx >= xx || ny < 0 || ny >= yy)) {
            return depth;
          }
          if (nx >= 0 && nx < xx && ny >= 0 && ny < yy && !vis[nx][ny] && maze[nx][ny] == '.') {
            vis[nx][ny] = true;
            dq.push_back({nx, ny});
          }
        }
        dq.pop_front();
      }
      ++depth;
    }
    return -1;
  }
};
