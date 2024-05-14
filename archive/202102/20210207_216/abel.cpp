class Solution {
public:
  vector<vector<int>> res;
  vector<int> cur;

  void dfs(int k, int start, int sum) {
    if (k == 0) {
      if (sum == 0) res.push_back(cur);
      return;
    }

    for (int i = start; i <= min(sum, 9); ++i) {
      cur.push_back(i);
      dfs(k - 1, i + 1, sum - i);
      cur.pop_back();
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    dfs(k, 1, n);

    return res;
  }
};
