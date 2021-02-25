class Solution {
public:
  bool check(vector<int>& a, int x) {
    int n = a.size();

    if (x == n - 1) return true;
    else if (x == 0) return a[0] != a[1];
    else {
      if (a[x] == a[x - 1]) return x % 2 == 0;
      else if (a[x] == a[x + 1]) return x & 1;
      else return true;
    }
  }

  int singleNonDuplicate(vector<int>& a) {
    int n = a.size();
    if (n == 1) return a[0];

    int l = 0, r = n - 1, mid;
    while (l < r) {
      mid = (l + r) >> 1;

      if (check(a, mid)) r = mid;
      else l = mid + 1;
    }
    return a[r];
  }
};
