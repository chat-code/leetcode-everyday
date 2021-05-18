class Solution {
public:
  int minSwaps(string s) {
    int n {}, m {};
    vector<char> s1(s.size(), '0');
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1') {s1[i] = '1'; ++n;}
      else ++m;
    }
    if (abs(n - m) > 1) return -1;

    int res = 0x3f3f3f3f, cnt = 0;
    vector<char> s2(s.size(), '0');

    if (n == m) {
      for (int i = 0; i < s.size(); ++i) {
        if (i & 1) s2[i] = '0';
        else s2[i] = '1';
      }

      cnt = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s1[i] != s2[i]) cnt++;
      }
      res = min(res, cnt / 2);

      cnt = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (i & 1) s2[i] = '1';
        else s2[i] = '0';
      }

      for (int i = 0; i < s.size(); ++i) {
        if (s1[i] != s2[i]) cnt++;
      }
      res = min(res, cnt / 2);

    } else if (n == m + 1) {
      for (int i = 0; i < s.size(); ++i) {
        if (i & 1) s2[i] = '0';
        else s2[i] = '1';
      }

      int cnt = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s1[i] != s2[i]) cnt++;
      }
      res = min(res, cnt / 2);
    } else if (n == m - 1) {
      cnt = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (i & 1) s2[i] = '1';
        else s2[i] = '0';
      }

      for (int i = 0; i < s.size(); ++i) {
        if (s1[i] != s2[i]) cnt++;
      }
      res = min(res, cnt / 2);
    }

    return res;
  }
};
