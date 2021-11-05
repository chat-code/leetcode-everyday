const int N = 500010, INF = 0x3f3f3f3f;
int d[N][4];

class Solution {
public:
  int minSideJumps(vector<int>& a) {
    int n = a.size();
    memset(d, 0x3f, sizeof d);

    d[0][2] = 0; d[0][1] = d[0][3] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= 3; ++j) {
        if (a[i] == j) continue;

        int &t = d[i][j];
        t = min(t, d[i - 1][j]);

        int j1 = (j + 1) % 3, j2 = (j + 2) % 3;
        if (!j1) j1 = 3;
        if (!j2) j2 = 3;

        t = min(t, d[i][j1] + 1);
        t = min(t, d[i][j2] + 1);
      }
      for (int j = 1; j <= 3; ++j) {
        if (a[i] == j) continue;

        int &t = d[i][j];
        t = min(t, d[i - 1][j]);

        int j1 = (j + 1) % 3, j2 = (j + 2) % 3;
        if (!j1) j1 = 3;
        if (!j2) j2 = 3;

        t = min(t, d[i][j1] + 1);
        t = min(t, d[i][j2] + 1);
      }
    }

    int res = INF;
    for (int i = 1; i <= 3; ++i) res = min(res, d[n-1][i]);
    return res;
  }
};
