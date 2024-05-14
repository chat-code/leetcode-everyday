#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int cnt[129] {};

    int n = int(s.size());
    if (n == 0) return 0;

    int res = 1;
    cnt[s[0]]++;
    for (int i = 1, j = 0; i < n; ++i) {
      cnt[s[i]]++;
      while (cnt[s[i]] > 1) {
        cnt[s[j++]]--;
      }
      res = max(res, i - j + 1);
    }

    return res;
  }
};
