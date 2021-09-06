class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int minn = nums.size() + 1;
    for (int i = 0; i < nums.size(); ++i) {
      auto fnd = m.find(nums[i]);
      if (fnd == m.cend()) {
        m.insert(make_pair(nums[i], i));
      } else {
        minn = min(minn, i - fnd->second);
        fnd->second = i;
      }
    }

    return minn != nums.size() + 1 && minn <= k;
  }
};
