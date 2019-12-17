#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using VI = vector<int>;

class Solution {
public:
  VI nums;
  Solution()
  {
    int t = 1, p = 10;
    for (int i = 2; i <= 9; i++, p *= 10)
      {
        int cnt = 10 - i, j = i, pre = t * 10 + i;
        while (cnt--)
          {
            t = t * 10 + j++;
            nums.push_back(t);
            t %= p;
          }
        t = pre;
      }
  }

  vector<int> sequentialDigits(int low, int high) {
    return VI(lower_bound(nums.begin(), nums.end(), low),
              upper_bound(nums.begin(), nums.end(), high));
  }
};

int main()
{
  Solution a;
  a.sequentialDigits(10, 1000);
  a.sequentialDigits(100, 300);

  return 0;
}
