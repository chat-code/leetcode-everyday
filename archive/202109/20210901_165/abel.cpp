class Solution {
public:
  int compareVersion(string v1, string v2) {
    int n = v1.size(), m = v2.size(), i = 0, j = 0, cur1 = 0, cur2 = 0;
    while (i < n || j < m) {
      cur1 = cur2 = 0;
      while (i < n && v1[i] != '.') {
        cur1 = cur1 * 10 + (v1[i] - '0');
        ++i;
      }
      while (j < m && v2[j] != '.') {
        cur2 = cur2 * 10 + (v2[j] - '0');
        ++j;
      }

      if (cur1 > cur2) return 1;
      else if (cur1 < cur2) return -1;

      ++i; ++j;
    }
    return 0;
  }
};
