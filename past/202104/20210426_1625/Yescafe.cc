// Runtime: 380 ms, faster than 29.04% of C++ online submissions for Lexicographically Smallest String After Applying Operations.
// Memory Usage: 88.9 MB, less than 63.61% of C++ online submissions for Lexicographically Smallest String After Applying Operations.

#include <set>
#include <algorithm>

class Solution {
public:
  string findLexSmallestString(string s, int a, int b) {
    findLexSmallestStringAux(s, a, b);
    return *min_element(iset.begin(), iset.end());
  }
  
  void findLexSmallestStringAux(string s, int a, int b) {
    // exists
    if (iset.find(s) != iset.end()) {
      return ;
    }
    iset.insert(s);
    
    string s1, s2;
    s1 = s2 = s;
    // gen s1
    for (int i = 1; i < s1.length(); i += 2) {
      s1[i] = (s1[i] - '0' + a) % 10 + '0';
    }
    findLexSmallestStringAux(s1, a, b);
    // gen s2
    rotate(s2.begin(), s2.begin() + b, s2.end());
    findLexSmallestStringAux(s2, a, b);
  }
private:
  set<string> iset;
};

