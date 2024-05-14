/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

#include <string>
using namespace std;

// @lc code=start
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 48.04 % of cpp submissions (6.2 MB)

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    string ss, ts;
    for (auto&& c : s) {
      if (c == '#') {
        if (!ss.empty()) ss.pop_back();
      } else {
        ss.push_back(c);
      }
    }
    for (auto&& c : t) {
      if (c == '#') {
        if (!ts.empty()) ts.pop_back();
      } else {
        ts.push_back(c);
      }
    }
    return ss == ts;
  }
};
// @lc code=end

