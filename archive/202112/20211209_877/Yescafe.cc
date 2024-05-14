class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    ///return true;
    int n = piles.size();
    vector<vector<int>> f(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
      f[i][i] = piles[i];
    for (int d = 1; d < n; ++d) {
      for (int i = 0; i + d < n; ++i) {
        int j = i + d;
        f[i][j] = max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1]);
      }
    }
    
    return f[0][n - 1] > 0;
  }
};

