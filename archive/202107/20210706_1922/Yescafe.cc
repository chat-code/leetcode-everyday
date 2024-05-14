class Solution {
  using ll = long long;
  const int MOD = 1e9 + 7;
public:
  int countGoodNumbers(long long n) {
    ll r = 1;
    
    r = timesmod(r, qpow(4, n / 2));
    r = timesmod(r, qpow(5, (n - 1) / 2 + 1));
    
    return r;
  }
private:
  ll qpow(ll a, ll b) {
    if (b == 0) return 1;
    else if (b == 1) return a;
    ll r = qpow(a, b / 2);
    if (b & 1) {
      return timesmod(timesmod(r, r), a);
    } else {
      return timesmod(r, r);
    }
  }
  ll timesmod(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
  }
};
