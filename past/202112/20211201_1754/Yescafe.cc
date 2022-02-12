class Solution {
public:
  string largestMerge(string word1, string word2) {
    stringstream ss;
    auto itr1 = word1.begin(), itr2 = word2.begin();
    while (itr1 != word1.end() && itr2 != word2.end()) {
      if (*itr1 > *itr2) {
        ss << *itr1++;
      } else if (*itr1 < *itr2) {
        ss << *itr2++;
      } else {
        if (!lexicographical_compare(itr1, word1.end(), itr2, word2.end())) {
          ss << *itr1++;
        } else {
          ss << *itr2++;
        }
      }
    }
    while (itr1 != word1.end()) {
      ss << *itr1++;
    }
    while (itr2 != word2.end()) {
      ss << *itr2++;
    }
    
    return ss.str();
  }
};
