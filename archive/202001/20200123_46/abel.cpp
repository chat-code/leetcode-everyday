const int N = 10;
int vis[N];

class Solution {
public:
  vector<vector<int>> res;
  vector<int> a;
  int n;

  void dfs(int k, vector<int>& cur) {
    if (k == n) {
      res.push_back(cur);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        vis[i] = 1;

        cur[k] = a[i];
        dfs(k + 1, cur);

        vis[i] = 0;
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    n = nums.size();
    if (n == 0) return res;

    a = nums;
    memset(vis, 0, sizeof vis);
    vector<int> cur(n, 0);
    dfs(0, cur);

    return res;
  }
};
