class Solution {
public:
  string sortString(string s) {
    int st[26] {}, n = s.size();
    for (int i = 0; i < n; ++i) st[s[i] - 'a']++;
    string res;
    while (res.size() != n) {
      for (int i = 0; i < 26; ++i) {
        if (st[i]) {
          res += char('a' + i);
          st[i]--;
        }
      }
      for (int i = 25; i >= 0; --i) {
        if (st[i]) {
          res += char('a' + i);
          st[i]--;
        }
      }
    }
    
    return res;
  }
};
