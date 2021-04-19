class Solution {
public:
  using VI = vector<int>;

  vector<int> partitionLabels(string a) {
    int m[128] {};

    int n = a.size();
    for (int i = 0; i < n; ++i) {
      m[a[i]] = max(m[a[i]], i);
    }

    VI res;

    for (int i = 0, j = m[a[i]]; j < n; ++j) {
      int st = i;
      j = m[a[i]];

      while (i < j) {
        j = max(j, m[a[i]]);
        ++i;
      }

      res.push_back(j - st + 1);
      i = j + 1;
    }

    return res;
  }
};
