class Solution {
public:
  int compress(vector<char>& a) {
    int n = a.size(), pos = 0, cnt = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      cnt = 0;
      while (j < n && a[i] == a[j]) {
        ++j, ++cnt;
      }
      a[pos++] = a[i];
      if (cnt == 1) continue;
      string num = to_string(cnt);
      for (auto &x : num) a[pos++] = x;
      i = j - 1;
    }
    return pos;
  }
};
