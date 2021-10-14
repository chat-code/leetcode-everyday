class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += nums[i];
    }
    int ma = sum;
    
    for (int i = k; i < nums.size(); ++i) {
      sum = sum - nums[i - k] + nums[i];
      ma = std::max(ma, sum);
    }
    
    return ma / (double) k;
  }
};

