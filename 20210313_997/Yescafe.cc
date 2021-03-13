/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 87.95 % of cpp submissions
// Your memory usage beats 79.51 % of cpp submissions (60.9 MB)

class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    std::vector<int> trustee(n + 1, 0);
    std::vector<int> truster(n + 1, 0);
    for (auto& v : trust) {
      ++trustee[v[1]];
      ++truster[v[0]];
    }

    int who = -1;
    for (int k = 1; k <= n; ++k) {
      if (trustee[k] == n - 1 && truster[k] == 0) {
        who = k;
        break;
      }
    }
    
    return who;
  }
};
// @lc code=end

