using ll = long long;

const int N = 110, MOD = 1e9+7;
int primes[N], cnt = 0;
bool st[N];

void get_primes(int n) {
  cnt = 0;
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) primes[cnt++] = i;
    for (int j = 0; primes[j] <= n / i; ++j) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) break;
    }
  }
}

class Solution {
public:
  int solve(int n) {
    int res = 1;
    for (int i = 1; i <= n; ++i)
      res = (ll(res) * i) % MOD;
    return res;
  }

  int numPrimeArrangements(int n) {
    get_primes(n);
    int res = solve(cnt);
    res = ll(res) * solve(n - cnt) % MOD;
    return res;
  }
};
