#include <iostream>

using namespace std;

class Solution {
public:
  int minimumBoxes(int n) {
    int k = 1, sum {0};

    while (true) {
      int tmp = k * (k + 1) / 2;
      if (n < tmp) {
        --k;
        break;
      }
      n -= tmp;
      ++k;
    }

    sum = k * (k + 1) / 2;

    k = 1;
    while (n >= k) {
      n -= k;
      ++sum;
      ++k;
    }
    if (n) ++sum;

    return sum;
  }
};
