#include <vector>

using namespace std;

class Solution {
public:

  int sumFourDivisors(vector<int>& nums) {
    int ans = 0;
    for (auto &x : nums) {
      unordered_map<int, int> primes;
      for (int i = 2; i <= x / i; ++i) {
        while (x % i == 0) {
          primes[i]++;
          x /= i;
        }
      }
      if (x > 1) primes[x]++;

      int y = 1;
      int sum = 1;
      for (auto &prime : primes) {
        int a = prime.first, b = prime.second;
        y = y * (1 + b);
        if (y > 4) { sum = 0; break; }
        int t = 1;
        while (b--) t = t * a + 1;
        sum *= t;
      }
      if (y == 4) ans += sum;
    }
    return ans;
  }
};
