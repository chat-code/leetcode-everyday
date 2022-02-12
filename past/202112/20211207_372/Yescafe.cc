class Solution {
public:
  int superPow(int a, vector<int>& b) {
    if (b.size() == 1 && b.back() == 0) return 1;
    if (a == 1) return 1;
    a %= MOD;
    
    long res = 1;

    for (int i = b.size() - 1; i >= 0; --i) {
      for (int _ = 0; _ < b[i]; ++_) {
        res = res * a % MOD;
      }
      int a2 = a * a % MOD;
      int a4 = a2 * a2 % MOD;
      int a8 = a4 * a4 % MOD;
      a = a2 * a8 % MOD;
    }
    
    return res % MOD;
  }

private:
  static constexpr int MOD = 1337;
};
