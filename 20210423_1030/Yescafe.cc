// Runtime: 40 ms, faster than 71.02% of C++ online submissions for Matrix Cells in Distance Order.
// Memory Usage: 16.5 MB, less than 82.39% of C++ online submissions for Matrix Cells in Distance Order.

class Solution {
public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> ret;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        ret.push_back({r, c});
      }
    }
    auto distance = [&](const int r, const int c) {
      return abs(r - r0) + abs(c - c0);
    };
    sort(ret.begin(), ret.end(), [&](const vector<int>& a, const vector<int>& b) {
      return distance(a[0], a[1]) < distance(b[0], b[1]);
    });
    return ret;
  }
};

