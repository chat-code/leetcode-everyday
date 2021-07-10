class Solution {
public:
  vector<int> buildArray(vector<int>& nums) {
    const int S = nums.size();
    vector<int> ans(S, 0);
    for (int i = 0; i < S; ++i)
      ans[i] = nums[nums[i]];
    return ans;
  }
};
