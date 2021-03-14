class Solution {
public:
    string mostCommonWord(string s, vector<string>& banned) {
      map<string, int> m;
      set<string> ban;
      for (auto &x : banned) ban.insert(x);

      string cur, res;
      int cnt = 0;
      for (int i = 0, j = 0; i < s.size(); ++i) {
        if (!isalpha(s[i])) { cur = ""; continue; }
        j = i;
        while (j < s.size() && isalpha(s[j])) {
          cur += tolower(s[j]);
          ++j;
        }
        if (ban.find(cur) == ban.end()) {
          m[cur]++;
          if (cnt < m[cur]) {
            cnt = m[cur];
            res = cur;
          }
        }
        i = j;
        cur = "";
      }
      return res;
    }
};
