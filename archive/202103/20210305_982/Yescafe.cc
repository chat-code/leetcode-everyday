/*
 * @lc app=leetcode id=982 lang=cpp
 *
 * [982] Triples with Bitwise AND Equal To Zero
 */

#include <iostream>
#include <vector>
using std::vector;

// @lc code=start
// Your runtime beats 44.91 % of cpp submissions
// Your memory usage beats 93.41 % of cpp submissions (7.3 MB)

class Solution {
public:
  int countTriplets(vector<int>& a) {
    int cnt[1 << 16] = {0};

    int ma = 0;
    for (int i = 0; i < a.size(); ++i) {
      ma = std::max(ma, a[i]);
      for (int j = 0; j < a.size(); ++j) {
        ++cnt[a[i] & a[j]];
      }
    }

    int bit_bound = 0;
    while (ma != 0) {
      ma >>= 1;
      ++bit_bound;
    }

    int res = 0;

    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < (1 << bit_bound); ++j) {
        if ((a[i] & j) == 0) {
          res += cnt[j];
        }
      }
    }

    return res;
  }
};
// @lc code=end

int main()
{
  std::vector a {2, 1, 3};
  std::cout << Solution().countTriplets(a) << std::endl;
  return 0;
}
