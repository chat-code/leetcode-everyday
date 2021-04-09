class Solution {
public:
  bool check(const string &a, const string &b) {
    int i = 0, j = 0, n = a.size(), m = b.size();

    for (; i < n && j < m; ++i) {
      if (a[i] == b[j]) ++j;
    }
    return j == m;
  }

  string findLongestWord(string s, vector<string>& a) {
    string res;
    sort(a.begin(), a.end(), [](const string &x, const string &y) {
      if (x.size() != y.size()) return (x.size() >= y.size());
      return x <= y;
    });

    for (auto &x : a) {
      if (check(s, x)) return x;
    }

    return res;
  }
};
