/*
Runtime: 48 ms, faster than 95.30% of C++ online submissions for As Far from Land as Possible.
Memory Usage: 18.8 MB, less than 80.69% of C++ online submissions for As Far from Land as Possible.
*/

#include <deque>

struct Coord {
  int x, y;
};

const int _directions[][2] = {1, 0, -1, 0, 0, 1, 0, -1};


// BFS solution
class Solution {
public:
  int maxDistance(vector<vector<int>>& grid) {
    std::deque<Coord> q;
    const auto _nx = grid.size(), _ny = grid[0].size();
    int res = 0;
    
    for (int x = 0; x < _nx; ++x)
      for (int y = 0; y < _ny; ++y)
        if (grid[x][y] == 1)
          q.push_back({x, y});
    
    
    // BFS by min path
    while (!q.empty()) {
      auto p = q.front();
      q.pop_front();
      for (int d = 0; d < 4; ++d) {
        auto x = p.x + _directions[d][0];
        auto y = p.y + _directions[d][1];
        
        if (x >= 0 && x < _nx && y >= 0 && y < _ny && grid[x][y] == 0) {
          grid[x][y] = grid[p.x][p.y] + 1;
          q.push_back({x, y});
          res = std::max(grid[x][y], res);
        }
      }
    }
    
    return res - 1;
  }
};
