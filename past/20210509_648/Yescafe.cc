// Runtime: 56 ms, faster than 74.37% of C++ online submissions for Replace Words.
// Memory Usage: 48.9 MB, less than 70.54% of C++ online submissions for Replace Words.

struct Trie {
  Trie* nodes[26];
  bool tail;
  Trie() {
    for (int i = 0; i < 26; ++i) {
      nodes[i] = nullptr;
    }
    tail = false;
  }
};

class Solution {
public:
  string replaceWords(vector<string>& dictionary, string sentence) {
    stringstream ss;
    Trie trie;
    for (auto&& word : dictionary) {
      Trie* cur = &trie;
      for (auto&& ch : word) {
        if (!cur->nodes[ch - 'a']) {
          cur->nodes[ch - 'a'] = new Trie;
        }
        cur = cur->nodes[ch - 'a'];
      }
      cur->tail = true;
    }
    
    Trie* cur = &trie;
    string word;
    for (int i = 0; i < sentence.length(); ++i) {
      if (sentence[i] == ' ') {
        ss << word << ' ';
        word = "";
        cur = &trie;
        continue;
      }
      
      if (cur->tail) {
        ss << word;
        while (i < sentence.length() && sentence[i] != ' ')
          ++i;
        if (i < sentence.length())
          ss << ' ';
        word.clear();
        cur = &trie;
        continue;
      }

      if (cur->nodes[sentence[i] - 'a']) {
        cur = cur->nodes[sentence[i] - 'a'];
        word.push_back(sentence[i]);
      } else {
        ss << word;
        while (i < sentence.length() && sentence[i] != ' ') {
          ss << sentence[i];
          i++;
        }
        if (i < sentence.length())
          ss << ' ';
        word.clear();
        cur = &trie;
      }
    }
    if (!word.empty())
      ss << word;
    return ss.str();
  }
};

