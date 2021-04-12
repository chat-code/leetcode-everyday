class Solution {
public:
  bool isPowerOfFour(int n) {
    if (n < 0) return false;
    if (n != (n & -n)) return false;
    return n % 3 == 1;
  }
};
