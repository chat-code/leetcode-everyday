/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

#include <string>
using std::string;
#include <iostream>

// @lc code=start
// Your runtime beats 25.26 % of cpp submissions
// Your memory usage beats 33.17 % of cpp submissions (46.5 MB)

#include <map>
#include <utility>

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() = default;
  
  /** Inserts a word into the trie. */
  void insert(string word) {
    ::Trie* curNode = this;
    for (auto&& c : word) {
      auto fnd = curNode->table.find(c);
      if (fnd == curNode->table.end())
        curNode->table[c] = {};
      curNode = &curNode->table[c];
    }
    curNode->table['\0'] = {};
  }
  
  /** Returns if the word is in the trie. */
  bool search(string word) {
    ::Trie* curNode = this;
    for (auto&& c : word) {
      auto fnd = curNode->table.find(c);
      if (fnd == curNode->table.end())
        return false;
      curNode = &fnd->second;
    }
    if (curNode->table.find('\0') != curNode->table.end())
      return true;
    return false;
  }
  
  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    ::Trie* curNode = this;
    for (auto&& c : prefix) {
      auto fnd = curNode->table.find(c);
      if (fnd == curNode->table.end())
        return false;
      curNode = &fnd->second;
    }
    return true;
  }

private:
  std::map<char, ::Trie> table;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

#include <iostream>
#include <cassert>

int main()
{
  std::string word {"abcde"};
  ::Trie* obj = new ::Trie();

  obj->insert(word);
  obj->search(word);

  delete obj;
}
