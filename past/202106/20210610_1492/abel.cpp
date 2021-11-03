const int N = 1010;

class Solution {
public:
  vector<int> get_divisors(int n) {
    vector<int> res;
    for (int i = 1; i <= n / i; ++i) {
      if (n % i == 0) {
        res.push_back(i);
        if (i != n / i) res.push_back(n / i);
      }
    }
    sort(res.begin(), res.end());
    return res;
  }

  int kthFactor(int n, int k) {
    vector<int> div = get_divisors(n);
    if (k > div.size()) return -1;
    return div[k - 1];
  }
};
