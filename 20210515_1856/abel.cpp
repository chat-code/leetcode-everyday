using VI = vector<int>;
using ll = long long;
const int MOD = 1e9 + 7, N = 100010, INF = 0x3f3f3f3f;
int Left[N], Right[N], stk[N];

class Solution {
public:
  int maxSumMinProduct(vector<int>& _a) {
    ll res = 0;
    int n = _a.size();
    vector<ll> pre(n + 1, 0);
    VI a(n + 2, 0);

    for (int i = 0; i < n; ++i) a[i + 1] = _a[i];
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];

    a[0] = a[n + 1] = -1;
    int tt = 0;
    stk[++tt] = 0;
    for (int i = 1; i <= n; ++i) {
      while (tt && a[stk[tt]] >= a[i]) --tt;
      Left[i] = stk[tt];
      stk[++tt] = i;
    }

    tt = 0;
    stk[++tt] = n + 1;
    for (int i = n; i >= 1; --i) {
      while (tt && a[stk[tt]] >= a[i]) --tt;
      Right[i] = stk[tt];
      stk[++tt] = i;
    }

    for (int i = 1; i <= n; ++i) {
      ll tmp = ll(pre[Right[i] - 1] - pre[Left[i]]) * a[i];
      res = max(res, tmp);
    }

    res %= MOD;

    return res;
  }
};
