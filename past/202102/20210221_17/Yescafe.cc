/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.5 MB, less than 90.73% of C++ online submissions for Letter Combinations of a Phone Number.
*/

const std::string imap[10] = {
  "", "", "abc", "def", "ghi",
  "jkl", "mno", "pqrs", "tuv", "wxyz"
};

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    std::vector<std::string> source {""};
    for (auto&& d : digits) {
      std::vector<std::string> results;
      for (auto&& s : source) {
        for (auto&& c : imap[d - '0']) {
          results.push_back(s + c);
        }
      }
      source = std::move(results);
    }
    if (source.front() != "")
      return source;
    return {};
  }
};
