/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 27.9 % of cpp submissions (8.7 MB)

class Solution {
public:
  vector<int> numsSameConsecDiff(int n, int k) {
    for (int digit = 1; digit <= 9; ++digit) {
      dfs(n - 1, k, digit, digit);
    }
    return ivec;
  }
private:
  void dfs(int n, int k, int digit, int ans) {
    if (n == 0) {
      ivec.push_back(ans);
      return ;
    }
    auto b1 = isSingleDigital(digit - k);
    auto b2 = isSingleDigital(digit + k);
    if (!b1 && !b2) {
      return ;
    }
    if (b1) {
      dfs(n - 1, k, digit - k, 10 * ans + (digit - k));
    }
    if (k != 0 && b2) {
      dfs(n - 1, k, digit + k, 10 * ans + (digit + k));
    }
  }

  bool isSingleDigital(int n) {
    return n >= 0 && n < 10;
  }

  void addDigital(int n, int k, int digit, int sign) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += (i & 1) ? digit + sign * k : digit;
      ans *= 10;
    }
    ans /= 10;
    ivec.push_back(ans);
  }

private:
  std::vector<int> ivec;

};
// @lc code=end

// testcase: 3\n1
