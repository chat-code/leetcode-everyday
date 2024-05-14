/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
#include <utility>

// @lc code=start
// Your runtime beats 91.32 % of cpp submissions
// Your memory usage beats 73.12 % of cpp submissions (8.1 MB)

class Solution {
public:
  int numSquares(int n) {
    std::vector<bool> visited(n + 1, false);
    std::deque<int> idq;

    for (int k = 1; k * k <= n; ++k) {
      idq.push_back(k * k);
    }
    // is a perfect square
    if (n == idq.back()) {
      return 1;
    }

    int cnt = 1;  // all perfect square < n already in queue
    while (!idq.empty() && cnt < 4) {
      auto size = idq.size();
      ++cnt;
      
      for (int i = 0; i < size; ++i) {
        auto front = idq.front();
        idq.pop_front();

        for (int k = 1; k * k <= n - front; ++k) {
          auto sq = k * k;
          if (front + sq == n) {
            return cnt;
          } else {
            if (visited[front + sq] == false) {
              visited[front + sq] = true;
              idq.push_back(front + sq);
            }
          }
        }
      }
    }

    return cnt;
  }
};
// @lc code=end

int main()
{
  int i;
  while (std::cin >> i) {
    std::cout << Solution().numSquares(i) << std::endl;
  }
  return 0;
}
