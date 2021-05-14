// Runtime: 4 ms, faster than 89.06% of C++ online submissions for Rectangle Area.
// Memory Usage: 5.7 MB, less than 94.96% of C++ online submissions for Rectangle Area.

class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, 
                  int bx1, int by1, int bx2, int by2) {
    int area1 = (ax2 - ax1) * (ay2 - ay1);
    int area2 = (bx2 - bx1) * (by2 - by1);
    int cx = 0, cy = 0;
    
    auto cross = [](int a1, int a2, int b1, int b2) {
      if (a1 < b1 && a2 < b1) {
        return 0;
      } else if (a1 < b1 && a2 == b1) {
        return 0;
      } else if (a1 < b1 && a2 > b1 && a2 < b2) {
        return a2 - b1;
      } else if (a1 < b1 && a2 == b2) {
        return a2 - b1;
      } else if (a1 < b1 && a2 > b2) {
        return b2 - b1;
      } else if (a1 == b1 && a2 > b1 && a2 < b2) {
        return a2 - b1;
      } else if (a1 == b1 && a2 == b2) {
        return b2 - b1;
      } else if (a1 == b1 && a2 > b2) {
        return b2 - b1;
      } else if (a1 > b1 && a1 < b2 && a2 > b1 && a2 < b2) {
        return a2 - a1;
      } else if (a1 > b1 && a1 < b2 && a2 == b2) {
        return b2 - a1;
      } else if (a1 > b1 && a1 < b2 && a2 > b2) {
        return b2 - a1;
      } else {
        return 0;
      }
    };
    
    cx = cross(ax1, ax2, bx1, bx2);
    cy = cross(ay1, ay2, by1, by2);
    
    return area1 + area2 - cx * cy;
  }
};

