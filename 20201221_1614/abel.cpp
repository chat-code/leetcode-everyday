class Solution {
public:
    int maxDepth(string s) {
      stack<char> stk;
      int n = s.size(), res = 0;
      for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
          stk.push(s[i]);
          res = max(res, int(stk.size()));
        } else if (s[i] == ')') stk.pop();
      }
      return res;
    }
};
