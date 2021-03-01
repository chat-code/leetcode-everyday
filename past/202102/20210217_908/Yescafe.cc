/*
Runtime: 16 ms, faster than 90.80% of C++ online submissions for Smallest Range I.
Memory Usage: 15.5 MB, less than 86.31% of C++ online submissions for Smallest Range I.
*/

#include <algorithm>

class Solution {
public:
  int smallestRangeI(vector<int>& a, int k) {
    auto p = std::minmax_element(a.begin(), a.end());
    if (*p.second - *p.first < 2 * k)
      return 0;
    return *p.second - *p.first - 2 * k;
  }
};

// 评价：
// 看到踩这么多，我也想说一句。什么 sb 题目。
