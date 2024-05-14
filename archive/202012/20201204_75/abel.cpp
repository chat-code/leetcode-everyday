class Solution {
public:
  using VI = vector<int>;
  VI a;

  void Qsort(int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
    while (i < j) {
      while (a[++i] < x);
      while (a[--j] > x);
      if (i < j) swap(a[i], a[j]);
    }
    Qsort(l, j);
    Qsort(j + 1, r);
  }

  void sortColors(vector<int>& nums) {
    a = nums;
    Qsort(0, a.size() - 1);
    nums = a;
  }
};
