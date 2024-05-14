class Solution {
  public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
      int n = dist.size();
      vector<double> t(n, 0);
      for (int i = 0; i < n; ++i) t[i] = 1.0 * dist[i] / speed[i];
      sort(t.begin(), t.end());
      int ans = 0, cur = 0;
      for (int i = 0; i < n; ++i) {
        if (t[i] <= cur) {
          break;
        }
        ++cur;
        ++ans;
      }
      return ans;
    }
};
