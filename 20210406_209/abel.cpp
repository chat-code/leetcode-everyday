using ll = long long;

class Solution {
public:
  int minSubArrayLen(int t, vector<int>& a) {
    int n = a.size(), res = n + 1;
    ll cur = 0;

    for (int i = 0, j = 0; j < n; ++j) {
      cur += a[j];
      while (i <= j && cur >= t) {
        res = min(res, j - i + 1);
        cur -= a[i];
        ++i;
      }
    }

    return res == (n + 1) ? 0 : res;
  }
};
