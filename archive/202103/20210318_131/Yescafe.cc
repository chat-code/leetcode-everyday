/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

#include <vector>
#include <string>
using std::vector;
using std::string;

// @lc code=start
// Your runtime beats 76.69 % of cpp submissions
// Your memory usage beats 45.5 % of cpp submissions (75.8 MB)

class Solution {
public:
  vector<vector<string>> partition(string s) {
    std::vector<std::string> sl;
    str = s;
    
    dfs(0, sl);

    return ans;
  }

private:
  void dfs(std::size_t idx, std::vector<std::string>& sl) {
    if (idx == str.length()) {
      ans.push_back(sl);
    }
    for (int len = 1; len <= str.length() - idx; ++len) {
      if (isPalindrome(idx, len)) {
        sl.push_back(str.substr(idx, len));
        dfs(idx + len, sl);
        sl.pop_back();
      }
    }
  }

  bool isPalindrome(std::size_t idx, std::size_t len) {
    for (int i = 0; i < len / 2; ++i)
      if (str[idx + i] != str[idx + len - 1 - i])
        return false;
    return true;
  }

private:
  std::vector<std::vector<std::string>> ans;
  std::string str;
};
// @lc code=end

