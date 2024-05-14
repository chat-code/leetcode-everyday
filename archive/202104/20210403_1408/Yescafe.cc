/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

#include <vector>
#include <string>
using std::vector;
using std::string;

// @lc code=start
// Your runtime beats 87.27 % of cpp submissions
// Your memory usage beats 86.93 % of cpp submissions (8.3 MB)

class Solution {
public:
  vector<string> stringMatching(vector<string>& words) {
    std::vector<std::string> substrs;
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words.size(); ++j) {
        if (i == j) continue;
        if (words[i].length() > words[j].length())
          continue;
        if (words[j].find(words[i]) != std::string::npos) {
          substrs.push_back(words[i]);
          break;
        }
      }
    }
    return substrs;
  }
};
// @lc code=end

