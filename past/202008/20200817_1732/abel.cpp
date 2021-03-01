#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int largestAltitude(vector<int> &a) {
    int res {0}, cur = 0;
    for (auto &x : a) {
      cur = cur + x;
      res = max(res, cur);
    }
    return res;
  }
};
