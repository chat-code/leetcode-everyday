class Solution {
public:
  bool isSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    for (; i < n; ++i) {
      while (j < m && s[i] != t[j]) ++j;
      if (j == m) return false;
      ++j;
    }
    return true;
  }
};
