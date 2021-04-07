class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size(), res = 0, cnt[26] {}, cur = 0;

    for (int i = 0, j = 0; j < n; ++j) {
      cnt[s[j] - 'A']++;
      cur = max(cur, cnt[s[j] - 'A']);

      while (i <= j && j - i + 1 - cur > k) {
        cnt[s[i++] - 'A']--;
      }
      res = max(res, j - i + 1);
    }

    return res;
  }
};
