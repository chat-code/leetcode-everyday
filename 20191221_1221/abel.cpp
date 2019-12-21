#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int balancedStringSplit(string s) {
    stack<char> st;
    if (s.size() == 0) return 0;
    st.push(s[0]);
    int res = 0;
    for (auto i = 1; i < s.size(); i++)
      {
        if (st.empty() || s[i] == st.top()) st.push(s[i]);
        else
          {
            st.pop();
            if (st.empty()) res++;
          }
      }
    return res;
  }
};

int main()
{
  Solution a;
  a.balancedStringSplit("RLRRLLRLRL");
  return 0;
}
