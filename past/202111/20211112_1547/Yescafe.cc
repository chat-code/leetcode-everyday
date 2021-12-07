class Solution {
public:
  int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(begin(cuts), end(cuts));
    constexpr int M = 1e9 + 7;
    int s = cuts.size();
    vector<vector<int>> f(s + 1, vector<int>(s + 1, M));
    for (int i = 0; i < f.size() - 1; ++i) {
      f[i][i + 1] = 0;
    }
    
    for (int d = 2; d < f.size(); ++d) {
      for (int i = 0, j = i + d; j < s; ++i, ++j) {
        for (int m = i; m <= j; ++m) {
          f[i][j] = min(f[i][j], f[i][m] + f[m][j] + (cuts[j] - cuts[i]));
        }
      }
    }
    
    return f[0][s - 1];
  }
};