class Solution {
public:
  int maxDistance(vector<int>& colors) {
    int maxx = -1;
    for (int i = 0; i < colors.size(); ++i) {
      for (int j = colors.size() - 1; j > i; --j) {
        if (colors[i] != colors[j]) {
          maxx = max(maxx, j - i);
        }
      }
    }
    return maxx;
  }
};
