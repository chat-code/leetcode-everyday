class Solution {
public:
  int countQuadruplets(vector<int>& nums) {
    cnt = 0;
    dfs(nums, 0, 0, 0);
    return cnt;
  }
  
private:
  void dfs(vector<int>& nums, int i, int p, int r) {
    if (i >= nums.size()) return ;
    else if (p == 3) {
      if (nums[i] == r) {
        ++cnt;
        dfs(nums, i + 1, p, r);
      } else {
        dfs(nums, i + 1, p, r);
      }
    } else {
      dfs(nums, i + 1, p, r);
      dfs(nums, i + 1, p + 1, r + nums[i]);
    }
  }
  
  int cnt;
};