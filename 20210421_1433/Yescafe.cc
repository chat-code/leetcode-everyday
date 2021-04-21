// Runtime: 76 ms, faster than 44.14% of C++ online submissions for Check If a String Can Break Another String.
// Memory Usage: 11.6 MB, less than 48.77% of C++ online submissions for Check If a String Can Break Another String.

#include <algorithm>

class Solution {
public:
  bool checkIfCanBreak(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    const auto len = s1.length();
    bool a1, a2;
    a1 = a2 = true;
    for (int i = 0; i < len; ++i) {
      if (s1[i] > s2[i]) {
        a1 = false;
        break;
      }
    }
    for (int i = 0; i < len; ++i) {
      if (s2[i] > s1[i]) {
        a2 = false;
        break;
      }
    }
    return a1 || a2;
  }
};
