class Solution {
public:
  int getMinDistance(vector<int>& a, int target, int start) {
    int res = 2000;
    for (int i = 0; i < a.size(); ++i) {
      if (target == a[i]) {
        res = min(res, abs(i - start));
      }
    }

    return res;
  }
};
