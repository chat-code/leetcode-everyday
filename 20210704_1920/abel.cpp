class Solution {
  public:
    vector<int> buildArray(vector<int>& a) {
      int n = a.size();
      vector<int> ans(n, 0);
      for (int i = 0; i < n; ++i) {
        ans[i] = a[a[i]];
      }
      return ans;
    }
};
