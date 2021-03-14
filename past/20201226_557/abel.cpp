class Solution {
public:
    string reverseWords(string s) {
      int n = s.size();
      for (int i = 0, j = 0; i < n; ++i) {
        j = i;
        while (isspace(s[i])) continue;
        while (j < n && !isspace(s[j])) ++j;
        for (int k1 = i, k2 = j - 1; k1 < k2; k1++, k2--) {
          swap(s[k1], s[k2]);
        }
        i = j;
      }
      return s;
    }
};
