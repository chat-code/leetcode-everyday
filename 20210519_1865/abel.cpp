using VI = vector<int>;

class FindSumPairs {
public:
  map<int, int> m;
  VI a, b;

  FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    m = map<int, int>();
    a = nums1;
    b = nums2;
    for (auto &x : b) {
      m[x]++;
    }
  }

  void add(int index, int val) {
    m[b[index]]--;
    b[index] += val;
    m[b[index]]++;
  }

  int count(int tot) {
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
      int x = tot - a[i];
      if (m.find(x) != m.end()) {
        res += m[x];
      }
    }
    return res;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
