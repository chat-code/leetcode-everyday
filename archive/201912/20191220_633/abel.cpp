#include <iostream>
class Solution {
public:
  bool judgeSquareSum(int c) {
    for (long long i = 0; i * i <= c; i++)
      {
        long long j = c - i * i, a = int(sqrt(j));
        if (a * a == j)
          return true;
      }
    return false;
  }
};
