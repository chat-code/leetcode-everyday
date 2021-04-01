/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

#include <iostream>
#include <vector>
using std::vector;

// @lc code=start
// Runtime: 4 ms, faster than 91.77% of C++ online submissions for String Compression.
// Memory Usage: 8.9 MB, less than 53.78% of C++ online submissions for String Compression.

#include <string>
#include <algorithm>

class Solution {
public:
  int compress(vector<char>& chars) {
    int n = chars.size();
    auto itr = chars.begin();
    auto begin = chars.begin();
    while (itr - chars.begin() != n) {
      if (*itr != *begin) {
        auto cnt = itr - begin;
        if (cnt == 1) {
          begin = itr;
        } else {
          auto cnts = std::to_string(cnt);
          n -= cnt - 1 - cnts.size();
          itr = chars.erase(begin + 1, itr);
          for (auto c = cnts.rbegin(); c != cnts.rend(); ++c)
            itr = chars.insert(itr, *c);
          begin = ++itr;
        }
        continue;
      }
      ++itr;
    }
    auto cnt = itr - begin;
    if (cnt == 1) {
      begin = itr;
    } else {
      auto cnts = std::to_string(cnt);
      n -= cnt - 1 - cnts.size();
      itr = chars.erase(begin + 1, itr);
      for (auto c = cnts.rbegin(); c != cnts.rend(); ++c)
        itr = chars.insert(itr, *c);
      begin = ++itr;
    }

    return n;
  }
};
// @lc code=end

