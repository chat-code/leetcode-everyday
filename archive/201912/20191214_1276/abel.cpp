#include <iostream>

using namespace std;
using VI = vector<int>;

class Solution {
public:
    vector<int> numOfBurgers(int a, int b) {
      int y = (4 * b - a) / 2, x = b - y;
      if (4 * x + 2 * y == a && x + y == b && x >= 0 && y >= 0)
	return VI {x, y};
      else return VI {};
    }
};
