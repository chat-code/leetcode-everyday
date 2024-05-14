#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  int numSquares(int n) {
    queue<int> q;
    vector<int> dist(n + 1, INT_MAX);
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
      int t = q.front(); q.pop();
      if (t == n) return dist[t];

      for (int j = 1; j * j + t <= n; ++j) {
        int i = j * j + t;
        if (dist[i] > dist[t] + 1) {
          dist[i] = dist[t] + 1;
          q.push(i);
        }
      }
    }

    return -1;
  }
};
