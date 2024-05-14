class Solution {
public:
  int n;
  vector<int> b;
  double H;

  bool check(double s) {
    double res = 0;
    for (int i = 0; i < n - 1; ++i) {
      res += int(ceil(b[i] / s));
    }
    res += b[n - 1] / s;
    return res <= H;
  }

  int bsearch() {
    int l = 1, r = 1e7 + 10, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (check(mid)) r = mid;
      else l = mid + 1;
    }

    return r;
  }

  int minSpeedOnTime(vector<int>& a, double h) {
    n = a.size();
    if (h < n - 1) return -1;

    b = a;
    H = h;

    return bsearch();
  }
};
