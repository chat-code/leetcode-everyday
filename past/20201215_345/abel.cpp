class Solution {
public:
  bool check(char c) {
    string s = "aeiou";
    char ch = tolower(c);
    for (auto &x : s) {
      if (ch == x) return true;
    }
    return false;
  }

    string reverseVowels(string s) {
      vector<int> pos;
      int n = s.size();
      for (int i = 0; i < n; ++i) {
        if (check(s[i])) pos.push_back(i);
      }

      n = pos.size();
      for (int i = 0, j = n - 1; i < j; i++, j--) {
        swap(s[pos[i]], s[pos[j]]);
      }

      return s;
    }
};
