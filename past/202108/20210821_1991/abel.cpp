class Solution {
public:
  int findMiddleIndex(vector<int>& a) {
    int sum = 0, n = a.size();
    for (int i = 0; i < n; ++i) sum += a[i];
    int res = -1, pre = 0;
    for (int i = 0; i < n; ++i) {
      if (i) {
        if (pre * 2 + a[i] == sum) return i;
      } else {
        if (sum - a[i] == 0) return 0;
      }
      pre += a[i];
    }
    return res;
  }
};
