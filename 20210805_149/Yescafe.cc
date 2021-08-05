class Solution {
public:
  int maxPoints(vector<vector<int>>& points) {
    const int n = points.size();
    if (n <= 2) return n;
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (ans > n / 2 || ans >= n - i) {
        break;
      }
      
      unordered_map<int, int> mp;
      for (int j = i + 1; j < n; ++j) {
        int dx = points[i][0] - points[j][0];
        int dy = points[i][1] - points[j][1];
        if (dx == 0) {
          dy = 1;
        } else if (dy == 0) {
          dx = 1;
        } else {
          if (dy < 0) {
            dy = -dy;
            dx = -dx;
          }
          int g = gcd(abs(dx), abs(dy));
          dx /= g, dy /= g;
        }
        int key = dy + 20001 * dx;
        auto v = ++mp[key];
        ans = max(ans, v + 1);
      }
    }
    
    return ans;
  }
  
private:
  static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
};
