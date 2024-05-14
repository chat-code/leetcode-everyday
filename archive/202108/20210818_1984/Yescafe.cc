class Solution {
public:
  int minimumDifference(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int minn = nums.back() - nums.front();
    for (int i = 0; i < n - k + 1; ++i) {
      minn = min(minn, nums[i + k - 1] - nums[i]);
    }
    return minn;
  }
};
