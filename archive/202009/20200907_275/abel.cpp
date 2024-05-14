class Solution {
public:

  int bsearch(vector<int>& a, int h) {
    int l = 0, r = a.size(), mid;
    while (l < r) {
      mid = (l + r) >> 1;

      if (a[mid] >= h) r = mid;
      else l = mid + 1;
    }

    return a.size() - r;
  }

  int hIndex(vector<int>& a) {
    int n = a.size();

    int l = 0, r = n, mid;
    while (l < r) {
      mid = (l + r + 1) >> 1;

      if (bsearch(a, mid) >= mid) l = mid;
      else r = mid - 1;
    }

    return l;
  }
};
