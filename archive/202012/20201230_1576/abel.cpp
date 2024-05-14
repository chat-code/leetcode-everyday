class Solution {
public:
    string modifyString(string s) {
      string res;
      int n = s.size();
      for (int i = 0; i < n; ++i) {
	if (s[i] == '?') {
	  char ch = 'a';
	  while (ch != 'z') {
	    if (i && res[i - 1] == ch) { ch++; continue; }
	    if (i < s.size() && s[i + 1] == ch) { ch++; continue; }
	    break;
	  }
	  res += ch;
	} else {
	  res += s[i];
	}
      }
      return res;
    }
};
