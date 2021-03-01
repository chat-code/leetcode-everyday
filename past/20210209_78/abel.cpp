const int N = 15;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < (1 << n); ++i) {
      vector<int> cur;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          cur.push_back(nums[j]);
        }
      }
      res.push_back(cur);
    }
    return res;
  }
};
