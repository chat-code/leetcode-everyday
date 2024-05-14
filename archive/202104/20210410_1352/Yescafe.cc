/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start
// Your runtime beats 5.07 % of cpp submissions
// Your memory usage beats 39.29 % of cpp submissions (70.2 MB)
#include <vector>
#include <numeric>
#include <functional>

class ProductOfNumbers {
public:
  ProductOfNumbers() = default;
    
  void add(int num) {
    seq.push_back(num);
  }
  
  int getProduct(int k) {
    return std::accumulate(seq.rbegin(), seq.rbegin() + k, 1, std::multiplies<>{});
  }

private:
  std::vector<int> seq;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

