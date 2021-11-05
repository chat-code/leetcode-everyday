class Solution {
public:
  bool isIdealPermutation(vector<int>& a) {
    for (int i = 0; i < a.size(); ++i) {
      if (abs(i - a[i]) > 1) return false;
    }
    return true;
  }
};
