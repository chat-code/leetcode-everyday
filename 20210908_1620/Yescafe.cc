class Solution {
public:
  vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    int ax, ay;
    int maxx = -1;
    
    for (int x = 0; x <= 50; ++x) {
      for (int y = 0; y <= 50; ++y) {
        int sum = 0;
        for (auto& t : towers) {
          double d = hypot(x - t[0], y - t[1]);
          if (d <= radius) {
            sum += floor(t[2] / (1 + d));
          }
        }
        if (sum > maxx)
          ax = x, ay = y, maxx = sum;
      }
    }
    
    return {ax, ay};
  }
};
