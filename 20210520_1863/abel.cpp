class Solution {
public:
  int subsetXORSum(vector<int>& a) {
    int n = a.size();
    int res = 0, N = (1 << n);

    for (int i = 0; i < N; ++i) {
      int tmp = 0, x = i, idx = 0;
      while (x) {
        if (x & 1)
          tmp ^= a[idx];
        x >>= 1;
        ++idx;
      }
      res += tmp;
    }

    return res;
  }
};
