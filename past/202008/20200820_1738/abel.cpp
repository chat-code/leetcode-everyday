#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1010;
int d[N][N], q[N*N];

class Solution {
public:
  int kthLargestValueV1(vector<vector<int>> &a, int k) {
    memset(d, 0, sizeof d);
    int m = a.size(), n = a[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        d[i][j] = a[i][j];
        if (j >= 1) d[i][j] ^= d[i][j-1];
        if (i >= 1) d[i][j] ^= d[i-1][j];
        if (j >= 1 && i >= 1) d[i][j] ^= d[i-1][j-1];
      }
    }

    priority_queue<int, vector<int>, greater<int>> que;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int tmp = d[i][j];

        if (que.size() < k) {
          que.push(tmp);
        } else {
          if (tmp > que.top()) {
            que.push(tmp);
            que.pop();
          }
        }
      }
    }

    return que.top();
  }

  int kthLargestValue(vector<vector<int>> &a, int k) {
    memset(d, 0, sizeof d);
    int m = a.size(), n = a[0].size();

    int idx = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        d[i][j] = a[i][j];
        if (j >= 1)
          d[i][j] ^= d[i][j - 1];
        if (i >= 1)
          d[i][j] ^= d[i - 1][j];
        if (j >= 1 && i >= 1)
          d[i][j] ^= d[i - 1][j - 1];

        q[idx++] = d[i][j];
      }
    }

    k = idx - k;
    nth_element(q, q + k, q + idx);
    return q[k];
  }
};
