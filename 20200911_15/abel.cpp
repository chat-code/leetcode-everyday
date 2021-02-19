class Solution {
public:
  using VI = vector<int>;
  vector<vector<int>> threeSum(vector<int>& a) {
    vector<VI> res;
    if (a.size() == 0) return res;

    sort(a.begin(), a.end());

    bool flag = false;
    int prev = 0, n = a.size();
    for (int i = 0; i < n; ++i) {
      if (i && flag && prev == a[i]) continue;

      prev = a[i];
      flag = false;
      int l = i + 1, r = n - 1, t = -a[i], prel = 0;

      while (l < r) {
        while (l < r && a[l] + a[r] > t) --r;
        if (l < r && a[l] + a[r] == t) {
          flag = true;
          prel = a[l];
          res.push_back({a[i], a[l], a[r]});
          --r;
        }
        ++l;
        while (flag && l < r && a[l] == prel) ++l;
      }
    }

    return res;
  }
};
