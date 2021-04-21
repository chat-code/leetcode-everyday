class Solution {
public:
  bool check_valid(const string &s, int i, int j) {
    for (; i < j; ++i, --j) {
      if (s[i] != s[j]) return false;
    }
    return true;
  }

  bool validPalindrome(string s) {
    int n = s.size();

    for (int i = 0, j = n - 1; i < j; ++i, --j) {
      if (s[i] == s[j]) continue;
      return check_valid(s, i + 1, j) || check_valid(s, i, j - 1);
    }

    return true;
  }
};
