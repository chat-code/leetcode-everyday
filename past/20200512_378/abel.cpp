class Solution {
public:
  int kthSmallest(vector<vector<int>>& a, int k) {
    int n = a.size();
    int l = a[0][0], r = a[n - 1][n - 1], mid;

    while (l < r) {
      mid = (l + r) / 2;

      int sum = 0, i = n - 1, j = 0;
      while (i >= 0) {
        while (j < n && a[i][j] <= mid) ++j;
        sum += j;
        --i;
      }
      if (sum >= k) r = mid;
      else l = mid + 1;
    }
    return r;
  }
};
