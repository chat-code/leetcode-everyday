class Solution {
public:
  int numRescueBoats(vector<int>& a, int k) {
    int res {};
    int n = a.size();
    sort(a.begin(), a.end());

    for (int i = 0, j = n - 1; i <= j;) {
      if (i == j) {
        ++res;
        ++i, --j;
        continue;
      }
      if (a[i] + a[j] > k) {
        res++;
        --j;
        continue;
      }
      res++;
      ++i, --j;
    }

    return res;
  }
};
