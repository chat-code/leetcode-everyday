const int N = 20;
int vis[N], n;

class Solution {
public:
  vector<int> a, cur;
  vector<vector<int>> res;

  void dfs(int k, int start) {
    if (k == n) {
      res.push_back(cur); return;
    }

    for (int i = start; i < n; ++i) {
      if (!vis[i]) {
        vis[i] = 1;

        cur[i] = a[k];

        if (k + 1 < n && a[k + 1] == a[k]) dfs(k + 1, i + 1);
        else dfs(k + 1, 0);

        vis[i] = 0;
      }
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    a = nums;
    n = a.size();
    memset(vis, 0, sizeof vis);
    cur = vector<int>(n, 0);

    dfs(0, 0);
    return res;
  }
};
