#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 26, INF = 0x3f3f3f3f;
int s1[N], s2[N];

class Solution {
public:

  int check(int a[], int b[]) {
    int res = INF;

    for (int i = 1; i < 26; ++i) {
      int tmp = 0;
      // a 中 >=i 的需要改變
      for (int j = i; j < 26; ++j) tmp += a[j];
      // b 中 <i 的需要改變
      for (int j = 0; j < i; ++j) tmp += b[j];

      res = min(res, tmp);
    }

    return res;
  }

  int minCharacters(string a, string b) {
    memset(s1, 0, sizeof s1);
    memset(s2, 0, sizeof s2);
    int m = a.size(), n = b.size();

    for (int i = 0; i < m; ++i) ++s1[a[i] - 'a'];
    for (int i = 0; i < n; ++i) ++s2[b[i] - 'a'];
    int res = INF;
    for (int i = 0; i < 26; ++i) {
      int tmp = m - s1[i] + n - s2[i];
      res = min(res, tmp);
    }

    res = min(res, min(check(s1, s2), check(s2, s1)));

    return res;
  }
};
