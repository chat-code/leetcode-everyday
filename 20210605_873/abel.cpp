#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
      int n = arr.size();
      vector<vector<int>> f(n, vector<int>(n, 2));
      int res = 0;
      unordered_map<int, int> pos;
      for (int i = 0; i < n; ++i) pos[arr[i]] = i;

      for (int j = 0; j <= n - 2; ++j) {
        for (int i = j + 1; i <= n - 1; ++i) {
          int x = arr[i] - arr[j];

          if (x < arr[j] && pos.count(x)) {
            int k = pos[x];
            f[i][j] = f[j][k] + 1;
            res = max(f[i][j], res);
          }
        }
      }

      if (res <= 2) return 0;

      return res;
    }
};
