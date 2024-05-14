class Solution {
public:
  int totalFruit(vector<int>& a) {
    map<int, int> s;
    int n = a.size(), res = 0;

    for (int i = 0, j = 0; j < n; ++j) {
      s[a[j]]++;
      while (s.size() > 2) {
        int t = a[i++];
        s[t]--;
        if (s[t] == 0) s.erase(t);
      }
      res = max(res, j - i + 1);
    }

    return res;
  }
};
