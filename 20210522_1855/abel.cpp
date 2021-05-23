class Solution {
public:
  int maxDistance(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    int i = 0, j = 0, res = 0;
    for (; j < m; ++j) {
      while (i <= j && i < n && a[i] > b[j]) ++i;
      if (i <= j && i < n && a[i] <= b[j]) {
        res = max(res, j - i);
      }
    }
    return res;
  }
};
