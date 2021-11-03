class Solution {
public:
  int lenLongestFibSubseq(vector<int>& arr) {
    const int n = arr.size();
    vector<vector<int>> f(n, vector<int>(n, 0));
    
    unordered_map<int, int> invert;
    for (int i = 0; i < n; ++i) {
      invert[arr[i]] = i;
      for (int j = i + 1; j < n; ++j) {
        f[i][j] = 2;
      }
    }
    
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int s = arr[i] + arr[j];
        auto fnd = invert.find(s);
        if (fnd != invert.end()) {
          int k = fnd->second;
          f[j][k] = f[i][j] + 1;
        }
      }
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ans = max(ans, f[i][j]);
      }
    }
    
    if (ans == 2) return 0;
    return ans;
  }
};
