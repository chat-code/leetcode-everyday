class Solution {
public:
  using ll = long long;
  bool isPowerOfTwo(int n) {
    if (!n) return false;
    ll x = n;
    return x == (x & -x);
  }
};
