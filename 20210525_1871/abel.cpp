class Solution {
public:
  bool canReach(string s, int a, int b) {
    int n = s.size();
    if (s[n - 1] == '1') return false;

    vector<int> p(n + 1, 0), st(n + 1, 0);

    st[1] = 1;
    p[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (s[i - 1] == '0') {
        int y = i - a, x = max(i - b, 1);
        if (y >= 1) {
          st[i] = (p[y] - p[x - 1] > 0);
        }
      }

      p[i] = p[i - 1] + st[i];
    }

    return st[n] > 0;
  }
};
