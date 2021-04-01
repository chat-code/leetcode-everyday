/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for To Lower Case.
Memory Usage: 5.8 MB, less than 94.95% of C++ online submissions for To Lower Case.
*/

#include <algorithm>
// #include <cctype>

class Solution {
public:
  string toLowerCase(string str) {
	  // std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::transform(str.begin(), str.end(), str.begin(), [](const auto& c) {
      return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
    });
    return str;
  }
};