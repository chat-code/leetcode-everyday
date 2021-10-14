const int N = 100010, M = 110;
int pre[M][N];

class Solution {
public:
  vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
    memset(pre, 0, sizeof pre);
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= 100; ++j) {
        pre[j][i + 1] = pre[j][i] + (j == nums[i]);
      }
    }

    vector<int> res;
    for (auto &q : queries) {
      int l = q[0], r = q[1], t = M, p = -1;
      for (int i = 1; i <= 100; ++i) {
        if (pre[i][r + 1] > pre[i][l]) {
          if (p == -1) {
            p = i;
            continue;
          } else {
            t = min(t, i - p);
            p = i;
          }
        }
      }
      if (t == M) t = -1;
      res.push_back(t);
    }

    return res;
  }
};
