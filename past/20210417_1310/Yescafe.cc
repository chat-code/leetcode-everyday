/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

#include <vector>
using std::vector;

// @lc code=start
// Runtime: 72 ms, faster than 89.52% of C++ online submissions for XOR Queries of a Subarray.
// Memory Usage: 38.1 MB, less than 59.24% of C++ online submissions for XOR Queries of a Subarray.

class Solution {
public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    std::vector<int> prefix(arr.size(), 0);
    for (int i = 0; i < arr.size(); ++i) {
      if (i == 0) prefix[0] = arr[0];
      else prefix[i] = prefix[i - 1] ^ arr[i];
    }
    std::vector<int> xors;
    for (auto& interval : queries) {
      int k = interval[0] == 0 ? 0 : prefix[interval[0] - 1];
      xors.push_back(prefix[interval[1]] ^ k);
    }
    return xors;
  }
};
// @lc code=end

