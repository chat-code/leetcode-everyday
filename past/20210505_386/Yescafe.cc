// Runtime: 8 ms, faster than 77.83% of C++ online submissions for Lexicographical Numbers.
// Memory Usage: 10.9 MB, less than 83.04% of C++ online submissions for Lexicographical Numbers.

class Solution {
public:
  vector<int> lexicalOrder(int n) {
    ret.reserve(n);
    for (int k = 1; k < 10; ++k) {
      if (k <= n) {
        lexicalOrderAux(k, n);
      } else {
        break;
      }
    }
    return ret;
  }
private:
  void lexicalOrderAux(int p, int n) {
    ret.push_back(p);
    for (int k = 0; k < 10; ++k) {
      int nn = p * 10 + k;
      if (nn <= n) {
        lexicalOrderAux(nn, n);
      } else {
        break;
      }
    }
  }
private:
  vector<int> ret;
};

