class Solution {
  using ll = long long;
public:
  int findNthDigit(int n) {
    ll k, nn;
    for (k = 1, nn = 9; ; ++k, nn *= 10) {
      if (n - k * nn < 0)
        break;
      n -= k * nn;
    }
    if (n == 0) return 9;
    int nth = (n - 1) / k, npos = (n - 1) % k;
    int nth_n = tens(k - 1) + nth;
    return to_string(nth_n)[npos] - '0';
  }
  
private:
  int tens(int p) {
    int res = 1;
    for (int i = 0; i < p; ++i) {
      res *= 10;
    }
    return res;
  }
};
