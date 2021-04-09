class Solution {
public:
    string generateTheString(int n) {
      string res;
      char ch = 'a';
      if (n & 1) {
        res += ch;
        ch++;
        n--;
      }
      if (n > 0) {
        res += ch;
        ch++;
        n--;
      }
      while (n--) {
        res += ch;
      }
      return res;
    }
};
