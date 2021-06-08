class Solution {
  const int MOD = 1e9 + 7;
public:
  int profitableSchemes(int n, int minProfit,
                        vector<int>& group, vector<int>& profit) {
    vector<vector<int>> f(n + 1, vector<int>(minProfit + 1));
    for (int i = 0; i <= n; ++i) f[i][0] = 1;
    
    for (int i = 0; i < group.size(); ++i) {
      for (int j = n; j >= group[i]; --j) {
        for (int k = minProfit; k >= 0; --k) {
          f[j][k] = (f[j][k] + f[j - group[i]][max(0, k - profit[i])]) % MOD;
        }
      }
    }
    
    return f.back().back();
  }
};
