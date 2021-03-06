class Solution {
public:
  int searchInsert(vector<int>& a, int target) {
    int n = a.size();
    int l = 0, r = n - 1, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (a[mid] >= target) r = mid;
      else l = mid + 1;
    }
    if (a[r] >= target) return r;
    return r + 1;
  }
};
