// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Numbers At Most N Given Digit Set.
// Memory Usage: 8.1 MB, less than 64.84% of C++ online submissions for Numbers At Most N Given Digit Set.

class Solution {
  using ll = long long;
public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    auto ns = std::to_string(n);
    auto len = ns.length();
    int res = 0;
    for (int l = 1; l <= len; ++l) {
      res += dfs(digits, l, ns, 0);
    }
    return res;
  }

private:
  int dfs(vector<string>& digits, int l, string& ns, int i) {
    auto len = ns.length();
    if (len == i) return 1;
    int n = stoi(ns);
    if (l < len) {
      return pow(digits.size(), l);   // l < len all permutations
    } else if (l > len) {
      return 0;
    } else {    // l == len
      int head = ns[i] - '0';
      for (int j = digits.size() - 1; j >= 0; --j) {
        auto digit = stoi(digits[j]);
        if (digit > head) {
          continue;
        } else if (digit == head) {
          return j * pow(digits.size(), l - 1 - i) + dfs(digits, l, ns, i + 1);
          break;
        } else {
          return (j + 1) * pow(digits.size(), l - 1 - i);
        }
      }
    }
    return 0;
  }

};

