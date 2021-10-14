class Solution {
public:
  int longestOnes(vector<int>& a, int K) {
    int n = a.size(), cur = 0, res = 0;

    for (int i = 0, j = 0; j < n; ++j) {
      if (a[j] == 0) ++cur;
      while (cur > K) {
        if (a[i++] == 0) cur--;
      }
      res = max(res, j - i + 1);
    }
    return res;
  }
};
