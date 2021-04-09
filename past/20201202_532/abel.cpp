class Solution {
public:
  int findPairs(vector<int>& a, int k) {
    int n = a.size(), res = 0;

    sort(a.begin(), a.end());

    for (int i = 0, j = 0; j < n; ++j) {
      while (i < j && a[j] - a[i] > k) {
        ++i;
      }

      if (i < j && a[j] - a[i] == k) {
        ++res;
        while (j + 1 < n && a[j] == a[j + 1]) ++j;
      }
    }

    return res;
  }
};
