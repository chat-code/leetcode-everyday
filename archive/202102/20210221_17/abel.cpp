class Solution {
public:
  string b[10] = {"", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"};

  vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) return res;

    res.push_back("");
    for (auto &u : digits) {
      vector<string> cur;
      for (auto &c : b[u - '0']) {
        for (auto &s : res) {
          cur.push_back(s + c);
        }
      }
      res = cur;
    }

    return res;
  }
};
