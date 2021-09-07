class Solution {
public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    vector<int> ans;
    int mask = (1 << maximumBit) - 1;
    int v = mask;
  
    for (auto&& n : nums) {
      v ^= n;
    }
    
    for (int i = nums.size() - 1; i >= 0; --i) {
      ans.push_back(v);
      v ^= nums[i];
    }
    
    return ans;
  }
};