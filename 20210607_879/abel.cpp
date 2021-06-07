const int MOD = 1e9 + 7;

class Solution {
public:
    int profitableSchemes(int n, int m, vector<int>& group, vector<int>& profit) {
      vector<vector<int>> d(n + 1, vector<int> (m + 1, 0));
      for (int i = 0; i <= n; ++i) d[i][0] = 1;

      for (int i = 0; i < group.size(); ++i) {
        int g = group[i], p = profit[i];
        for (int j = n; j >= g; --j) {
          for (int k = m; k >= 0; --k) {
            d[j][k] += d[j - g][max(0, k - p)];
            d[j][k] %= MOD;
          }
        }
      }

      return d[n][m];
    }
};
