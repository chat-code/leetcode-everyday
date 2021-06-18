class Solution {
public:
  bool isLongPressedName(string name, string typed) {
    if (typed.length() < name.length()) return false;
    int i, j;
    for (i = 0, j = 0; i < name.length(); ) {
      if (i == 0) {
        if (name.front() != typed.front()) {
          return false;
        }
        ++j;
      } else {
        if (name[i] != typed[j]) {
          if (name[i - 1] != typed[j]) {
            return false;
          }
          while (j < typed.length() && name[i - 1] == typed[j]) {
            ++j;
          }
          continue;
        } else {
          ++j;
        }
      }
      ++i;
    }
    while (j < typed.length() && typed[j] == name.back()) ++j;
    if (i >= name.length() && j >= typed.length())
      return true;
    return false;
  }
};
