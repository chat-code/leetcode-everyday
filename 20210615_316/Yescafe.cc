class Solution {
public:
  string removeDuplicateLetters(string s) {
    vector<int> idx(26, -1);
    vector<bool> vis(26, false);
   
    for (int i = 0; i < s.length(); ++i) {
      idx[s[i] - 'a'] = i;
    }
    
    vector<char> stk;
    for (int i = 0; i < s.length(); ++i) {
      if (vis[s[i] - 'a']) {
        continue;
      } else if (stk.empty() || stk.back() < s[i]) {
        stk.push_back(s[i]);
        vis[s[i] - 'a'] = true;
      } else {
        while (!stk.empty() && stk.back() >= s[i] && idx[stk.back() - 'a'] > i) {
          vis[stk.back() - 'a'] = false;
          stk.pop_back();
        }
        if (!vis[s[i] - 'a']) {
          stk.push_back(s[i]);
          vis[s[i] - 'a'] = true;
        }
      }
    }
    
    string ret(stk.begin(), stk.end());
    return ret;
  }
};
