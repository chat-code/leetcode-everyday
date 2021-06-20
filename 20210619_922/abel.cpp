class Solution {
public:
  vector<int> sortArrayByParityII(vector<int>& a) {
    int n = a.size(), i = 0, j = n - 1;
    while (i < n) {
      while (i < n && a[i] % 2 == 0) i += 2;
      while (j > 0 && a[j] % 2 == 1) j -= 2;
      if (i < n) swap(a[i], a[j]);
    }
    return a;
  }
};
