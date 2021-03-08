/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 */

// @lc code=start
// Your runtime beats 84.9 % of cpp submissions
// Your memory usage beats 89.61 % of cpp submissions (8 MB)

class Solution {
public:
  int maxSatisfaction(vector<int>& s) {
    std::sort(s.begin(), s.end());
    int res = 0, selected_sum = 0;
    for (auto itr = s.rbegin(); itr != s.rend(); ++itr) {
      if (res + *itr + selected_sum < res) {
        break;
      }
      res = res + *itr + selected_sum;
      selected_sum += *itr;
    }
    return res;
  }
};
// @lc code=end

