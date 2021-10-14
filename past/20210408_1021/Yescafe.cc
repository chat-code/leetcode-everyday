/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

#include <string>
using std::string;
#include <iostream>

// @lc code=start
// Your runtime beats 79.45 % of cpp submissions
// Your memory usage beats 97.16 % of cpp submissions (6.5 MB)

class Solution {
public:
  string removeOuterParentheses(string s) {
    std::size_t left_idx = -1;   // std::string::npos
    std::string s2;
    int stack_depth = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
        ++stack_depth;
        if (left_idx == -1)
          left_idx = i;
      } else {   // ')'
        --stack_depth;
      }
      if (stack_depth == 0) {
        s2 += s.substr(left_idx + 1, i - left_idx - 1);   // [left_idx + 1, i - 1)
        left_idx = -1;   // update for next match
      }
    }
    return s2;
  }
};
// @lc code=end

