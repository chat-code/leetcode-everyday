class Solution {
public:
  bool wordPattern(string pattern, string s) {
    string m[26];
    set<string> added;
    string word;
    stringstream ss;
    ss << s;
    int i = 0;
    auto len = pattern.length();
    
    while (ss >> word) {
      if (i >= len) return false;
      if (added.find(word) != added.end()) {   // found
        if (word != m[pattern[i] - 'a']) {
          return false;
        }
      } else {    // not found
        if (!m[pattern[i] - 'a'].empty()) return false;
        m[pattern[i] - 'a'] = word;
        added.insert(word);
      }
      ++i;
    }
    
    if (i < len) return false;
    return true;
  }
};
