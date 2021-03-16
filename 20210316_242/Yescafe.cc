/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

#include <string>
using std::string;

// @lc code=start
// Runtime: 8 ms, faster than 83.29% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.3 MB, less than 38.88% of C++ online submissions for Valid Anagram.

#include <map>

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    int cnt[26] = { 0 };
    for (auto&& c : s)
      ++cnt[c - 'a'];
    for (auto&& c : t)
      --cnt[c - 'a'];
    bool ret = true;
    for (auto&& n : cnt) {
      if (n != 0) {
        ret = false;
        break;
      }
    }

    return ret;
  }
};
// @lc code=end

