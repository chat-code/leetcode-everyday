/*
Runtime: 8 ms, faster than 75.23% of C++ online submissions for Get Equal Substrings Within Budget.
Memory Usage: 7.5 MB, less than 95.05% of C++ online submissions for Get Equal Substrings Within Budget.
*/

// #include <iostream>
// #include <string>
// using std::string;
#include <cmath>

class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int left, right;
    left = right = 0;
    int maxLength = 0;
    int length = 0;

    while (right != s.size()) {
      auto cost = std::abs(s[right] - t[right]);
      if (cost > maxCost) {
        auto left_cost = std::abs(s[left] - t[left]);
        maxCost += left_cost;
        ++left;
        --length;
        continue;
      }
      maxCost -= cost;
      ++length;
      maxLength = std::max(maxLength, length);
      ++right;
      // std::cout << left << ' ' << right << std::endl;
    }

    return maxLength;
  }
};

// #include <cassert>

// int main() {
//   std::string s, t;
//   int maxCost;
//   while (std::cin >> s >> t >> maxCost) {
//     std::cout << Solution().equalSubstring(s, t, maxCost) << std::endl;
//   }
//   return 0;
// }

// 评价：
// 蛮 classic 的双指针问题。之后在讨论区看到这种算法叫 slide window。
// 不是很清楚这样子的算法能不能算 O(N)，因为稍微改写一下 if ... continue 的组合也可以很容易变成 nested loop。

// 看了一下别人的答案，发现有两三个变量好像是不需要的，我自己写的时候没有注意优化。
