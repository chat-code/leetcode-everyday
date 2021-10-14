class Solution {
public:
  const int MOD = 1e9 + 7;
  using ll = long long;
  
  ll gcd(ll a, ll b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }
  
  int nthMagicalNumber(int n, int a, int b) {
    ll lcm = a / gcd(a, b) * b;
    ll low = 1, high = 1e18;
    ll mid;
    while (low < high) {
      mid = (low + high) / 2;
      ll count = mid / a + mid / b - mid / lcm;
      if (count < n)
        low = mid + 1;
      else
        high = mid;
    }
    
    return low % MOD;
  }
};