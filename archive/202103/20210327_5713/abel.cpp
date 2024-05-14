class Solution {
public:
  string strip(string s) {
    int i = 0, n = s.size();
    while (i < n && s[i] == '0') ++i;

    string r = s.substr(i);
    if (r.size() == 0) r = "0";
    return r;
  }

  int numDifferentIntegers(string a) {
    set<string> si;
    string cur {};
    int n = a.size();
    bool flag {};

    for (int i = 0; i < n; ++i) {
      if (isalpha(a[i])) {
        if (flag) {
          flag = !flag;
          si.insert(strip(cur));
          cur = "";
          continue;
        }
      } else if (isdigit(a[i])) {
        cur = cur + a[i];
        flag = true;
      }
    }

    if (flag) {
      si.insert(strip(cur));
    }

    return si.size();
  }
};
