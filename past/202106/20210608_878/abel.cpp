using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  ll g;

  int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
  }

  bool check(ll x, int n, int a, int b) {
    return x / a + x / b - x / g >= n;
  }

    int nthMagicalNumber(int n, int a, int b) {
      g = ll(a) * b / gcd(a, b);

      ll left = 1, right = 4 * 1e13, mid;

      while (left < right) {
        mid = (left + right) >> 1;
        if (check(mid, n, a, b)) right = mid;
        else left = mid + 1;
      }

      return right % MOD;
    }
};
