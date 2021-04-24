// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate String.
// Memory Usage: 5.9 MB, less than 90.80% of C++ online submissions for Rotate String.

class Solution {
public:
  bool rotateString(string a, string b) {
    if (a.length() != b.length()) return false;
    if (a.empty() && b.empty()) return true;
    const auto len = a.length();
    for (int i = 0; i < len; ++i) {
      bool identical = true;
      for (int j = 0; j < len; ++j) {
        if (a[j] != b[(i + j) % len]) {
          identical = false;
          break;
        }
      }
      if (identical)
        return true;
    }
    return false;
  }
};
