class Solution {
public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> f(n1 + 1, vector<int>(n2 + 1, {}));
    
    for (int i = 0; i <= n1; ++i) {
      for (int j = 0; j <= n2; ++j) {
        if (i == 0 || j == 0)
          f[i][j] = 0;
        else if (nums1[i - 1] == nums2[j - 1])
          f[i][j] = 1 + f[i - 1][j - 1];
        else
          f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      }
    }
    
    return f.back().back();
  }
};
