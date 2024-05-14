class Solution {
public:
  int arraySign(vector<int>& a) {
    int res = 1;
    for (auto &x : a) {
      if (x == 0) { res = 0; break; }
      else if (x < 0) { res = -res; }
    }
    return res;
  }
};
