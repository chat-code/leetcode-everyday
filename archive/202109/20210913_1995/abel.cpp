class Solution {
public:
    int countQuadruplets(vector<int>& a) {
      int res = 0, n = a.size();
      for (int i = 0; i < n; ++i) {
	for (int j = i + 1; j < n; ++j) {
	  for (int k = j + 1; k < n; ++k) {
	    for (int m = k + 1; m < n; ++m) {
	      if (a[i] + a[j] + a[k] == a[m]) ++res;
	    }
	  }
	}
      }
      return res;
    }
};
