/*
Runtime: 4 ms, faster than 56.82% of C++ online submissions for Optimal Division.
Memory Usage: 8.1 MB, less than 69.70% of C++ online submissions for Optimal Division.
*/

#include <sstream>
#include <algorithm>
#include <functional>

class Solution {
public:
  string optimalDivision(vector<int>& nums) {
    if (nums.size() == 1) return std::to_string(nums.front());
    std::stringstream ss;
    ss << nums[0] << '/';
    if (nums.size() > 2) ss << '(';
    for (int i = 1; i < nums.size(); ++i) {
      if (i != 1) ss << '/';
      ss << nums[i];
    }
    if (nums.size() > 2) ss << ')';
    return ss.str();
  }
};

// 评价：
// 憨憨我的甚至先想到了一个 O(N*2^N) 和 O(2^N) 的算法，嘿嘿。
// 最后是 O(N)，不过懒得再优化内存了。
