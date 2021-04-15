/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 */

#include <string>
using std::string;
#include <iostream>

// @lc code=start
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 57.31 % of cpp submissions (6 MB)

#include <sstream>

class Solution {
public:
  string strWithout3a3b(int a, int b) {
    if (a == 1 && b == 0) return "a";
    if (a == 0 && b == 1) return "b";
    std::stringstream ss;
    if (a > b) {
      int diff = a - b - 2;
      for (int i = 0; i < diff; ++i) {
        ss << "aab";
        --b;
        a -= 2;
      }
      while (a != 0 && b != 0) {
        ss << "ab";
        --a;
        --b;
      }
      while (a != 0) {
        ss << "a";
        --a;
      }
    } else if (a == b) {
      for (int i = 0; i < a; ++i)
        ss << "ab";
    } else {
      int diff = b - a - 2;
      for (int i = 0; i < diff; ++i) {
        ss << "bba";
        --a;
        b -= 2;
      }
      while (a != 0 && b != 0) {
        ss << "ba";
        --a;
        --b;
      }
      while (b != 0) {
        ss << "b";
        --b;
      }
    }
    return ss.str();
  }
};
// @lc code=end

int main()
{
  int a = 4;
  int b = 3;
  std::cout << Solution().strWithout3a3b(a, b) << std::endl;
  return 0;
}
