class Solution {
public:
  using VI = vector<int>;

  int numberOfArithmeticSlices(vector<int>& a) {
    int res {};

    int n = a.size();
    VI d(n, 0);

    for (int i = 2; i < n; ++i) {
      if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) {
        d[i] = d[i - 1] + 1;
      }
      res += d[i];
    }

    return res;
  }
};
