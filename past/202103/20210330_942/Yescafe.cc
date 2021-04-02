/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */

#include <vector>
#include <string>
using std::vector;
using std::string;
#include <iostream>

// @lc code=start
// Runtime: 4 ms, faster than 92.99% of C++ online submissions for DI String Match.
// Memory Usage: 8.7 MB, less than 69.67% of C++ online submissions for DI String Match.

#include <cassert>

class Solution {
public:
  vector<int> diStringMatch(string s) {
    seq.reserve(s.length() + 1);
    upper = s.length(), lower = 0;

    switch(s.front()) {
     case 'I': seq.push_back(lower++); break;
     default: seq.push_back(upper--);
    }

    continuous_count = 0;
    prev_ch = s.front();
    for (auto&& ch : s) {
      if (prev_ch == ch) {
        ++continuous_count;
      } else {
        gen();
        continuous_count = 1;
        prev_ch = ch;
      }
    }
    gen();

    // std::cerr << "L50 " << lower << " " << upper << std::endl;
    assert(lower - 1 == upper);
    return seq;
  }

private:
  void gen() {
    switch(prev_ch) {
     case 'I':
      upper -= continuous_count;
      for (int i = 0; i < continuous_count; ++i) {
        seq.push_back(upper + i + 1);
        // std::cerr << "I " << upper + i + 1 << std::endl;
      }
      break;
     default:
      lower += continuous_count;
      for (int i = 0; i < continuous_count; ++i) {
        seq.push_back(lower - i - 1);
        // std::cerr << "D " << lower - i - 1 << std::endl;
      }
    }
  }

  std::vector<int> seq;
  int upper, lower;
  int continuous_count;
  char prev_ch;
};
// @lc code=end

#include <iterator>
#include <algorithm>

int main()
{
  std::string input;
  std::cin >> input;
  auto seq = Solution().diStringMatch(input);
  std::copy(seq.begin(), seq.end(), std::ostream_iterator<int>(std::cout, " "));
  return 0;
}