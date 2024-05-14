class Solution {
public:
  string convert(string s, int k) {
    if (k == 1) return s;

    vector<string> ans(k, "");
    bool flag = true;
    int n = s.size(), j = 0, del = 1;

    for (int i = 0; i < n; ++i) {
      ans[j] += s[i];

      if (j + del == k) del = -1;
      else if (j + del < 0) del = 1;

      j += del;
    }

    string res;
    for (int i = 0; i < k; ++i) res += ans[i];

    return res;
  }
};
