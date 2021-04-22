// Runtime: 36 ms, faster than 58.41% of C++ online submissions for Largest Perimeter Triangle.
// Memory Usage: 21.8 MB, less than 59.03% of C++ online submissions for Largest Perimeter Triangle.

#include <functional>

class Solution {
public:
  int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    int ma = 0;
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (nums[i] < nums[i + 1] + nums[i + 2]) {
        ma = nums[i] + nums[i + 1] + nums[i + 2];
        break;
      }
    }
    return ma;
  }
};
