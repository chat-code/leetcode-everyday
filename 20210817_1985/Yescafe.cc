class Solution {
public:
  string kthLargestNumber(vector<string>& nums, int k) {
    auto ks = nums.begin() + k - 1;
    nth_element(nums.begin(), ks, nums.end(), [](const string& a, const string& b) {
      if (a.length() != b.length()) {
        return a.length() > b.length();
      } else {
        return a > b;
      }
    });
    return *ks;
  }
};
