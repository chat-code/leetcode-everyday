/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Perfect Number.
Memory Usage: 5.9 MB, less than 77.74% of C++ online submissions for Perfect Number.
*/

#include <cmath>

/**
test set:
28
6
496
8128
2
1
10000000
**/

class Solution {
public:
  bool checkPerfectNumber(int num) {
    if (num == 1) return false;  // specfied
    int sqrt = (int) ::sqrt(num) + 1;
    int sum = 1;       // here `num` is not 1 && 1 is always one of the divisors
    for (int k = 2; k < sqrt; ++k) {
      if (num % k == 0) {
        auto other = num / k;
        if (other != k)      // `num` is a perfect square number
          sum += other;
        sum += k;
      }
    }
    return sum == num;
  }
};

/*
#include <iostream>

int main() {
  int i;
  while (std::cin >> i) {
    std::cout << std::boolalpha << Solution().checkPerfectNumber(i)
              << std::endl;
  }
  return 0;
}
*/
