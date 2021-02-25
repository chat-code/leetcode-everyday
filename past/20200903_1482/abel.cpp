#include <vector>

using namespace std;

class Solution {
public:
  int minDays(vector<int> &a, int m, int k) {
    int n = a.size();
    if (m * k > n) return -1;

    int l = 1, r = -1, mid;
    for (int i = 0; i < n; ++i) r = max(r, a[i]);

    while (l < r) {
      mid = (l + r) >> 1;

      bool flag = false;
      int cnt = 0, cur = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] > mid) {
          cnt += cur / k;
          cur = 0;
          if (cnt >= m) {
            flag = true;
            break;
          }
        } else {
          ++cur;
        }
      }
      if (cur) {
        cnt += cur / k;
        if (cnt >= m) flag = true;
      }

      if (flag) r = mid;
      else l = mid + 1;
    }

    return r;
  }
};
