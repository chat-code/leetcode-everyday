class Solution {
public:
  int minAddToMakeValid(string s) {
    stack<char> st;
    int res {};
    for (auto c : s) {
      if (c == '(') {
        st.push(c);
      } else {
        if (!st.empty()) {
          st.pop();
        } else {
          ++res;
        }
      }
    }
    res += st.size();

    return res;
  }
};
