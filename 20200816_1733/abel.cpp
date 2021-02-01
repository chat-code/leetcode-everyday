#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int N = 510;

class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>> &lg, vector<vector<int>> &fs) {
    int m = lg.size();

    int g[N][N] {}, pe[N] {};

    for (int i = 0; i < m; ++i) {
      for (auto &l : lg[i]) {
        g[l][i + 1] = 1;
      }
    }

    for (auto &v : fs) {
      int a = v[0], b = v[1];
      bool flag = false;
      for (int i = 1; i <= n; ++i) {
        if (g[i][a] && g[i][b]) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        pe[a] = pe[b] = 1;
      }
    }

    int cnt[N] {};
    int maj = 0, pop {0};
    for (int i = 1; i <= m; ++i) {
      if (pe[i]) {
        ++pop;
        for (int j = 1; j <= n; ++j) {
          if (g[j][i]) {
            ++cnt[j];
            maj = max(maj, cnt[j]);
          }
        }
      }
    }

    return pop - maj;
  }
};
