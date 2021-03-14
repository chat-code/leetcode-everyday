class Solution {
public:
    bool buddyStrings(string a, string b) {
      int n = a.size(), m = b.size();

      if (m != n) return false;
      vector<int> pos;
      int st[26] {};

      for (int i = 0; i < n; ++i) {
        st[a[i] - 'a']++;
        if (a[i] != b[i]) {
          pos.push_back(i);
          if (pos.size() > 2) return false;
        }
      }

      if (pos.size() == 2) {
        return (a[pos[0]] == b[pos[1]] && a[pos[1]] == b[pos[0]]);
      }
      else if (pos.size() == 1) return false;
      
      for (int i = 0; i < 26; ++i) {
        if (st[i] >= 2) return true;
      }
      return false;
    }
};
