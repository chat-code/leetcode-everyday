class Solution {
public:
  int integerBreak(int n) {
    int d[60] {};
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        int &t = d[i];
        t = max(t, j * (i - j));
        t = max(t, j * d[i - j]);
      }
    }
    return d[n];
  }
};
