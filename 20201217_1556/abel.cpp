class Solution {
public:
    string thousandSeparator(int n) {
      if (!n) return "0";
      string res;
      int cur = 0;
      while (n) {
        if (cur && cur % 3 == 0) res += ".";
        res = res + char(n % 10 + '0');
        cur++;
        n /= 10;
      }
      reverse(res.begin(), res.end());
      return res;
    }
};
