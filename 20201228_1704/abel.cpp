class Solution {
public:
  bool check(char a) {
    string s = "aeiouAEIOU";
    for (auto &x : s) if (a == x) return true;
    return false;
  }
  bool halvesAreAlike(string s) {
    int st1 = 0, st2 = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
      if (i < n / 2) {
        st1 += check(s[i]);
      } else {
        st2 += check(s[i]);
      }
    }
    return st1 == st2;
  }
};
