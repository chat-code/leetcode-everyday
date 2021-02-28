/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 6.4 MB, less than 33.77% of C++ online submissions for Valid Parentheses.
*/

#include <list>

class Solution {
public:
  bool isValid(std::string s) {
    if (s.size() & 1) return false;    // s.size() is an odd
    for (auto&& c : s) {
      if (stack.empty()) {
        stack.push_back(c);
        continue;
      }
      switch(c) {
        case '(': case '[': case '{':
          stack.push_back(c);
          break;
        case ')':
          if (stack.back() == '(') stack.pop_back();
          else return false;
          break;
        case ']':
          if (stack.back() == '[') stack.pop_back();
          else return false;
          break;
        case '}':
          if (stack.back() == '{') stack.pop_back();
          else return false;
          break;
      }
    }
    if (!stack.empty()) return false;
    return true;
  }
  
private:
  std::list<char> stack;
};
