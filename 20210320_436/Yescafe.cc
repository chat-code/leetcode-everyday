/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 87.04 % of cpp submissions
// Your memory usage beats 83.4 % of cpp submissions (26 MB)

#include <algorithm>

class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    std::vector<int> ends;
    ends.reserve(intervals.size());
    for (int i = 0; i < intervals.size(); ++i) {
      ends.push_back(intervals[i][1]);
      intervals[i].push_back(i);
    }
    std::sort(intervals.begin(), intervals.end(), [](const auto& v1, const auto& v2) {
      return v1[0] < v2[0];
    });
    for (auto& end : ends) {
      auto fnd = std::upper_bound(intervals.begin(), intervals.end(), end, \
        [](const auto& e, const auto& v) {
          return e <= v[0];
        });
      if (fnd == intervals.end())
        end = -1;
      else
        end = fnd->operator[](2); 
    }
    return ends;
  }
};
// @lc code=end

