using VI = vector<int>;

class Solution {
public:
  double findMaxAverage(vector<int>& a, int k) {
    double res {}, sum {};
    int i = 0, j = 0, n = a.size();
    for (; i < k; ++i) sum += a[i];
    res = sum;
    for (i = 0, j = k; j < n; ++j, ++i) {
      sum -= a[i];
      sum += a[j];
      res = max(res, sum);
    }
    return res / k;
  }
};
