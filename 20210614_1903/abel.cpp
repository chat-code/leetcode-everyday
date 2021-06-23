class Solution {
public:
  string largestOddNumber(string num) {
    int n = num.size();
    int pos = -1;
    for (int i = n - 1; i >= 0; --i) {
      if ((num[i] - '0') & 1) {
        pos = i;
        break;
      }
    }
    if (pos == -1) return "";
    return num.substr(0, pos + 1);
  }
};
