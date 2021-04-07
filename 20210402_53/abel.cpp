using ll = long long;
const int INF = 0x3f3f3f3f;

class Solution {
public:
  int maxSubArray(vector<int>& a) {
    ll res = -INF, cur = 0;
    int n = a.size();

    res = a[0];
    cur = res;

    for (int i = 1; i < n; ++i) {
      if (cur < 0) cur = a[i];
      else cur += a[i];

      res = max(res, cur);
    }
    return res;
  }
};
