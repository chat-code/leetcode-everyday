class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int n = grid.size();
    int m1[n], m2[n];
    for (int i = 0; i < n; ++i) {
      m1[i] = m2[i] = -1;
      for (int j = 0; j < n; ++j) {
        m1[i] = max(m1[i], grid[i][j]);     // slow
        m2[i] = max(m2[i], grid[j][i]);     // fast
      }
    }
    
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        res += min(m1[i], m2[j]) - grid[i][j];
      }
    }
    
    return res;
  }
};

