/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start

// Your runtime beats 99.31 % of cpp submissions
// Your memory usage beats 74.62 % of cpp submissions (9.6 MB)

#include <map>

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int a = 0, b = 0;
    for (auto&& i : nums) {
      a ^= i;
      a &= ~b;
      b ^= i;
      b &= ~a;
    }
    return a;
  }
};
// @lc code=end

// Your runtime beats 34.19 % of cpp submissions
// Your memory usage beats 25.09 % of cpp submissions (10 MB)
/*
#include <map>

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    std::unordered_map<int, int> imap;
    for (auto&& i : nums) {
      ++imap[i];
    }
    for (auto&& p : imap) {
      if (p.second == 1)
        return p.first;
    }
    return nums.front();
  }
};
*/

// 评价：
// 初见杀的题目，抄标答了。虽说 Data Lab 是我盲做通的，但是如今遇到这种位运算的题目还是，不会。
