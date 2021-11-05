// Runtime: 4 ms, faster than 73.72% of C++ online submissions for Greatest Common Divisor of Strings.
// Memory Usage: 6.7 MB, less than 96.42% of C++ online submissions for Greatest Common Divisor of Strings.

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    return gcdOfStringsAux(str1, 0, str2, 0);
  }
 private:
  string gcdOfStringsAux(string& str1, int idx1, string& str2, int idx2) {
    auto len1 = str1.length() - idx1, len2 = str2.length() - idx2;
    if (len1 == 0) return str2.substr(idx2);
    if (len2 == 0) return str1.substr(idx1);
    if (len1 == len2) {
      auto ss1 = str1.substr(idx1), ss2 = str2.substr(idx2);
      if (ss1 == ss2) {
        return ss1;
      } else {
        return {};
      }
    } else if (len1 < len2) {
      for (int i = 0; i < len1; ++i) {
        if (str1[idx1 + i] != str2[idx2 + i]) {
          return {};
        }
      }
      return gcdOfStringsAux(str1, idx1, str2, idx2 + len1);
    } else {     // len1 > len2
      for (int i = 0; i < len2; ++i) {
        if (str1[idx1 + i] != str2[idx2 + i]) {
          return {};
        }
      }
      return gcdOfStringsAux(str1, idx1 + len2, str2, idx2);
    }
    return {};
  }
};

// 评价：
// 写了一个跟辗转相除法理念差不多的算法

