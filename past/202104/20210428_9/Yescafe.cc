// untime: 4 ms, faster than 93.11% of C++ online submissions for Palindrome Number.
// Memory Usage: 5.9 MB, less than 23.71% of C++ online submissions for Palindrome Number.

#include <string>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    string num = to_string(x);
    for (int i = 0; i < num.length() / 2; ++i) {
      if (num[i] != num[num.length() - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};

