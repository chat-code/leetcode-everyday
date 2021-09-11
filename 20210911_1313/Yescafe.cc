class Solution {
public:
  vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> vec;
    for (int i = 0; i < nums.size(); i += 2) {
      for (int j = 0; j < nums[i]; ++j) {
        vec.push_back(nums[i + 1]);
      }
    }
    return vec;
  }
}