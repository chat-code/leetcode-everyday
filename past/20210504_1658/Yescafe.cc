// Runtime: 152 ms, faster than 70.72% of C++ online submissions for Minimum Operations to Reduce X to Zero.
// Memory Usage: 98.6 MB, less than 52.88% of C++ online submissions for Minimum Operations to Reduce X to Zero.

class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < x) return -1;
    else if (sum == x) return nums.size();
    int y = sum - x;
    int left = 0, right = 0;
    int mi = nums.size() + 1;
    int t = 0;
    while (right != nums.size()) {
      t += nums[right++];
      while (t > y) {
        t -= nums[left++];
      }
      if (t == y)
        if (nums.size() - (right - left) < mi)
          mi = nums.size() - (right - left);
    }
    if (mi > nums.size())
      return -1;
    return mi;
  }
};

