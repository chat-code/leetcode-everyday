class Solution {
public:
    int countSegments(string s) {
      int res = 0, n = s.size();
      bool flag = false;
      for (int i = 0; i < n; ++i) {
        if (isspace(s[i])) {
          flag = false;
          continue;
        }
        if (!flag) {
          flag = true;
          res++;
        }
      }
      return res;
    }
};
