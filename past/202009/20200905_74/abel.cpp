
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& a, int x) {
    int n = a.size(), m = a[0].size();

    int l = 0, r = n - 1, mid;
    while (l < r) {
      mid = (l + r + 1) >> 1;

      if (a[mid][0] == x) return true;
      else if (a[mid][0] <= x) l = mid;
      else r = mid - 1;
    }
    if (a[l][0] > x) return false;
    if (a[l][0] == x) return true;

    int row = l;
    l = 0, r = m - 1;
    while (l < r) {
      mid = (l + r + 1) >> 1;

      if (a[row][mid] == x) return true;
      else if (a[row][mid] < x) l = mid;
      else r = mid - 1;
    }
    return a[row][l] == x;
  }
};
