class Solution {
public:
    int lengthOfLastWord(string s) {
      int res = 0, cur = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (isspace(s[i])) { cur = 0; continue; }
        else {
          cur++;
          res = cur;
        }
      }
      return res;
    }
};
