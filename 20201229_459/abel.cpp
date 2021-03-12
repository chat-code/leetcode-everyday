const int M = 10010, N = 20010;
char s[N], p[M];
int n, m, ne[M];

class Solution {
public:
    bool repeatedSubstringPattern(string s1) {
      memset(ne, 0, sizeof ne);
      m = s1.size();
      n = m * 2;
      
      for (int i = 0; i < m; ++i) {
	p[i + 1] = s[i + 1] = s[i + 1 + m] = s1[i];
      }

      for (int i = 2, j = 0; i <= m; ++i) {
	while (j && p[i] != p[j + 1]) j = ne[j];
	if (p[i] == p[j + 1]) ++j;
	ne[i] = j;
      }

      for (int i = 1, j = 0; i <= n; ++i) {
	while (j && s[i] != p[j + 1]) j = ne[j];
	if (s[i] == p[j + 1]) ++j;
	if (j == m) {
	  j = ne[j];
	  int k = i - m + 1;
	  if (k != 1 && k != m + 1) return true;
	}
      }
      return false;
    }
};

