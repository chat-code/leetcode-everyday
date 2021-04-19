class Solution {
public:
  using VI = vector<int>;
  using PII = pair<int, int>;

  int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
    int res {};

    int n = d.size();
    vector<PII> dp;
    for (int i = 0; i < n; ++i) dp.push_back({d[i], p[i]});
    sort(dp.begin(), dp.end());

    VI m(n, 0);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      cur = max(cur, dp[i].second);
      m[i] = cur;
    }

    int n1 = w.size();
    for (int i = 0; i < n1; ++i) {
      int l = 0, r = n - 1, mid;
      while (l < r) {
        mid = (l + r + 1) / 2;
        if (dp[mid].first <= w[i]) l = mid;
        else r = mid - 1;
      }
      if (dp[l].first <= w[i]) {
        res += m[l];
      }
    }

    return res;
  }
};
