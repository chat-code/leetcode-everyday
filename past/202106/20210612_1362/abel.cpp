class Solution {
public:
  vector<int> res;
  int m;

  void solve(int n) {
    for (int i = 1; i <= n / i; ++i) {
      if (n % i == 0) {
        if (n / i - i <= m) {
          m = n/i - i;
          res = vector<int>{n/i, i};
        }
      }
    }
  }

  vector<int> closestDivisors(int num) {
    m = num;
    solve(num + 1);
    solve(num + 2);
    return res;
  }
};
