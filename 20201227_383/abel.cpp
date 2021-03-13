const int N = 30;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      int st1[N] {}, st2[N] {};
      for (auto &x : ransomNote) st1[x - 'a']++;
      for (auto &x : magazine) st2[x - 'a']++;
      bool flag = true;
      for (int i = 0; i < 26; ++i) {
        if (st1[i] > st2[i]) return false;
      }
      return flag;
    }
};
