/*
 * @lc app=leetcode id=676 lang=cpp
 *
 * [676] Implement Magic Dictionary
 */

#include <vector>
#include <string>
using std::vector;
using std::string;
#include <iostream>
#define DEBUG 1
#define ifd if(DEBUG)

// @lc code=start
// Your runtime beats 63.9 % of cpp submissions
// Your memory usage beats 60.73 % of cpp submissions (55.6 MB)

#include <map>

class MagicDictionary {
public:
  /** Initialize your data structure here. */
  MagicDictionary() = default;
  
  void buildDict(std::vector<string> dictionary) {
    for (auto&& word : dictionary) {
      this->addWordStartWithIdx(word, 0);
    }
  }
  
  bool search(std::string searchWord) {
    return searchInTrieR(searchWord, 0, false);
  }

  MagicDictionary& operator[](char key) {
    return trie[key];
  }

  friend std::ostream& operator<<(std::ostream& os, const MagicDictionary&) {
    return (os << "ln36. ::MagicDictionary::operator<<");
  }

private:
  // add word[idx] into current trie, recursive
  void addWordStartWithIdx(std::string& word, std::size_t idx) {
    if (idx == word.size()) {
      trie.insert(std::make_pair<char, ::MagicDictionary>(0, {}));
      return ;
    }
    trie[word[idx]].addWordStartWithIdx(word, idx + 1);
  }

  // search in trie recursively
  bool searchInTrieR(std::string& word, std::size_t idx, bool hasReplaced) {
    if (hasReplaced) {
      if (idx == word.size()) {
        auto fnd = trie.find(0);
        if (fnd != trie.end()) {   // tail exists
          return true;
        } else {
          return false;
        }
      }
      auto fnd = trie.find(word[idx]);
      if (fnd == trie.end())
        return false;
      // assert hasReplaced == true
      return fnd->second.searchInTrieR(word, idx + 1, hasReplaced);
    } else {
      if (idx == word.size()) {
        return false;     // identical string
      }
      bool ret = false;
      for (auto&& p : trie) {
        if (ret) return ret;     // return true
        ret = p.second.searchInTrieR(word, idx + 1, p.first != word[idx]);
      }
      return ret;
    }
  }

private:
  std::map<char, ::MagicDictionary> trie;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end

int main()
{
  ::MagicDictionary md;
  md.buildDict({"hello", "leetcode"});
  ifd std::cout << md['h']['e']['l']['l']['o'][0] << std::endl;
  std::cout << std::boolalpha 
            << md.search("hello") << std::endl
            << md.search("hhllo") << std::endl      // true
            << md.search("hell") << std::endl
            << md.search("leetcoded") << std::endl
            << md.search("leetcode") << std::endl;
}
