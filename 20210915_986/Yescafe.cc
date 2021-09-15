class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> intervals;
    
    int i = 0, j = 0;
    while (i != a.size() && j != b.size()) {
      int left = max(a[i][0], b[j][0]);
      int right = min(a[i][1], b[j][1]);
      
      if (right - left >= 0)
        intervals.push_back({left, right});
      if (a[i][1] < b[j][1])
        ++i;
      else
        ++j;
    }
    
    return intervals;
  }
};
