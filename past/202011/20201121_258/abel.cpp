class Solution {
public:
  int addDigits(int n) {
    if (n < 10) return n;
    int x = n % 9;
    if (!x) return 9;
    return x;
  }
};
