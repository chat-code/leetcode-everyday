/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

#include <vector>
#include <iostream>
#include <cstring>

// @lc code=start
// Your runtime beats 96.16 % of cpp submissions
// Your memory usage beats 87.7 % of cpp submissions (9.1 MB)

class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    int dp[10010];
    std::memset(dp, 0, sizeof(int) * 10010);
    int m = -1;
    for (auto n : nums) {
      dp[n] += n;
      m = std::max(m, n);
    }
    for (int i = 2; i <= m; ++i) {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + dp[i]);
    }

    return dp[m];
  }
};
// @lc code=end

// 是我不会的 DP 了，别骂了别骂了，在学了在学了
