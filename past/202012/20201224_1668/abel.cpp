const int M = 110, N = 110;
int n, m, ne[M];
char s[N], p[M];

class Solution {
public:
    int maxRepeating(string sequence, string word) {
      memset(ne, 0, sizeof ne);
      n = sequence.size(), m = word.size();

      for (int i = 0; i < n; ++i) s[i + 1] = sequence[i];
      for (int i = 0; i < m; ++i) p[i + 1] = word[i];

      for (int i = 2, j = 0; i <= m; ++i) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) ++j;
        ne[i] = j;
      }
      
      int st[N] {};
      for (int i = 1, j = 0; i <= n; ++i) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) ++j;
        if (j == m) {
          j = ne[j];
          int k = i - m + 1;
          st[k] = 1;
        }
      }

      int res = 0;
      for (int i = 1; i <= n; ++i) {
        if (i >= m && st[i]) {
          st[i] += st[i - m];
        }
        res = max(res, st[i]);
      }

      return res;
    }
};
