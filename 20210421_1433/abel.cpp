class Solution {
public:
  bool checkIfCanBreak(string s1, string s2) {
    vector<char> a(s1.begin(), s1.end()), b(s2.begin(), s2.end());

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int n = a.size();
    bool flag = true;

    for (int i = 0; i < n; ++i) {
      if (a[i] < b[i]) {
        flag = false;
        break;
      }
    }
    if (flag) return true;

    flag = true;
    for (int i = 0; i < n; ++i) {
      if (a[i] > b[i]) {
        flag = false;
        break;
      }
    }
    return flag;
  }
};
