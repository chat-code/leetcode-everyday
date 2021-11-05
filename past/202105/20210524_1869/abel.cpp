class Solution {
public:
  int solve(char c, string &s) {
    int res = 0, cur = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == c) {
        cur++;
        res = max(res, cur);
      } else {
        cur = 0;
      }
    }
    return res;
  }

  bool checkZeroOnes(string s) {
    int n = s.size();
    int c0 = solve('0', s), c1 = solve('1', s);
    return c1 > c0;
  }
};
