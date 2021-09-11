class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int a = 0, cnt = 0;
    for (auto& n : nums) {
      if (cnt == 0) a = n;
      if (n == a) ++cnt;
      else --cnt;
    }
    return a;
  }
};