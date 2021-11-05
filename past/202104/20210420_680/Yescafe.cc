/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

#include <iostream>

#include <string>
using namespace std;

// @lc code=start
// Runtime: 64 ms, faster than 42.36% of C++ online submissions for Valid Palindrome II.
// Memory Usage: 23.1 MB, less than 48.51% of C++ online submissions for Valid Palindrome II.

class Solution {
public:
  bool validPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left <= right) {
      if (s[left] != s[right]) {
        return isPalindrome(s.substr(left, right - left))
          || isPalindrome(s.substr(left + 1, right - left));
      }
      ++left, --right;
    }
    return true;
  }
private:
  bool isPalindrome(const string& str) {
    for (int i = 0; i < str.length() / 2; ++i)
      if (str[i] != str[str.length() - 1 - i])
        return false;
    return true;
  }
};
// @lc code=end

int main()
{
  std::string str {"aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"};
  std::cout << std::boolalpha << Solution().validPalindrome(str) << std::endl;

  return 0;
}

