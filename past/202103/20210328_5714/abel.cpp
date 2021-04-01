class Solution {
public:
  string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> kn;
    for (auto &x : knowledge) {
      kn[x[0]] = x[1];
    }

    int n = s.size();
    string cur, res;
    for (int i = 0, j = 0; i < n; ++i) {
      if (isalpha(s[i])) {
        res += s[i];
        continue;
      }
      if (s[i] == '(') {
        cur = "";
        ++i;
        while (i < n && s[i] != ')') {
          cur += s[i];
          ++i;
        }
        string tmp;
        if (kn.find(cur) == kn.end()) { tmp = "?"; }
        else tmp = kn[cur];
        res += tmp;
      }
    }
    return res;
  }
};
