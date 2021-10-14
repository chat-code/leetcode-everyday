class Solution {
public:
  string strWithout3a3b(int a, int b) {
    string res;

    if (a > b) {
      int n = min(a - b, b);
      a -= n * 2;
      b -= n;

      string k = "aab";
      while (n--) res += k;

      if (a == b) {
        k = "ab";
        while (a--) res += k;
      } else {
        while (a--) res += 'a';
      }
    } else if (b > a) {
      int n = min(b - a, a);
      a -= n;
      b -= n * 2;

      string k = "bba";
      while (n--) res += k;

      if (a == b) {
        k = "ba";
        while (a--) res += k;
      } else {
        while (b--) res += 'b';
      }
    } else {
      string k = "ab";
      while (a--) res += k;
    }

    return res;
  }
};
