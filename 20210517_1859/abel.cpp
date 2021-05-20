class Solution {
public:
  string sortSentence(string s) {
    string res;
    stringstream ss(s);
    string tmp;
    vector<string> vs(10, "");
    int cnt = 0;

    while (ss >> tmp) {
      ++cnt;
      int sz = tmp.size();
      int i = tmp[sz - 1] - '0';
      vs[i - 1] = tmp.substr(0, sz - 1);
    }

    for (int i = 0; i < cnt; ++i) {
      res += vs[i];
      if (i != cnt - 1) res += ' ';
    }

    return res;
  }
};
