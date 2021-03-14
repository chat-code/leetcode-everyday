/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */
#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 81.18 % of cpp submissions
// Your memory usage beats 54.79 % of cpp submissions (99.6 MB)
#include <algorithm>
#include <set>

class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    starts.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      starts[i] = i;
    }
    for (const auto& p : edges) {
      starts[p[1]] = getStarts(p[0]);
    }

    std::set<int> is;
    for (int nd = 0; nd != n; ++nd) {
      is.insert(getStarts(nd));
    }
    std::vector<int> iv(is.begin(), is.end());
    std::sort(iv.begin(), iv.end());
    return iv;
  }

private:
  int getStarts(int idx) {
    if (idx == starts[idx]) return idx;
    int st = getStarts(starts[idx]);
    starts[idx] = st;
    return st;
  }

private:
  std::vector<int> starts;
};
// @lc code=end

// 评价：
// 并查集。我不会优化，就这样了。
