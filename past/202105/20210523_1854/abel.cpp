class Solution {
public:
  int maximumPopulation(vector<vector<int>>& a) {
    int res = 0, y = 0x3f3f3f3f;
    map<int, int> m;

    for (auto &x : a) {
      for (int i = x[0]; i < x[1]; ++i) {
        m[i]++;
        if (m[i] > res) {
          res = m[i];
          y = i;
        } else if (m[i] == res) {
          if (y > i) { y = i; }
        }
      }
    }

    return y;
  }
};
