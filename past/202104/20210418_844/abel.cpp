class Solution {
public:
  string get(string &a) {
    int i, j;
    for (i = -1, j = 0; j < a.size(); ++j) {
      if (isalpha(a[j])) {
        a[++i] = a[j];
      } else {
        if (i >= 0) --i;
      }
    }

    return a.substr(0, i + 1);
  }

  bool backspaceCompare(string s, string t) {
    return get(s) == get(t);
  }
};
