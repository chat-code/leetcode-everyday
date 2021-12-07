class Solution {
public:
  Solution() {
    vowels[0] = 'a', vowels[1] = 'e', vowels[2] = 'i', vowels[3] = 'o', vowels[4] = 'u';
    for (int i = 0; i < 5; ++i) {
      cnts[vowels[i]] = 0;
    }
  }
  
  int countVowelSubstrings(string word) {
    if (word.length() < 5) return 0;   // sp
    int res = 0;
    
    int s = -1;
    for (int i = 0; i < word.length(); ++i) {
      if (not_vowel(word[i])) {
        s = -1;
        for (auto& v : vowels) cnts[v] = 0;
        continue;
      } else if (s == -1) {
        s = i;
      }
      ++cnts[word[i]];
      if (i - s >= 4) {
        if (any_zero()) {
          continue;
        }
        int ns = s;
        do {
          ++res;
          --cnts[word[ns++]];
        } while (cnts[word[ns - 1]] != 0);
        for (int ii = s; ii < ns; ++ii) {
          ++cnts[word[ii]];
        }
      }
    }
    
    return res;
  }
private:
  char vowels[5];
  map<char, int> cnts;
  bool is_vowel(char c) {
    for (auto& v : vowels) {
      if (c == v) return true;
    }
    return false;
  }
  bool not_vowel(char c) {
    return !is_vowel(c);
  }
  bool any_zero() {
    for (auto& v : vowels) {
      if (cnts[v] == 0) return true;
    }
    return false;
  }
};
