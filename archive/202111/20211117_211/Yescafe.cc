class WordDictionary {
  struct Trie {
    unordered_map<char, Trie*> next;
    bool eow;
    Trie() : next{}, eow{false} {}
    Trie* next_or_create(char c) {
      if (next.find(c) == next.end())
        next[c] = new Trie;
      return next[c];
    }
    bool has_next(char c) {
      return next.find(c) != next.end();
    }
  };

public:
  void addWord(string word) {
    Trie* trie = &root;
    for (char& c : word) {
      trie = trie->next_or_create(c);
    }
    trie->eow = true;
  }

  bool search(string word) {
    return search(word, 0, &root);
  }

  bool search(string& word, int pos, Trie* trie) {
    for (int i = pos; i < word.length(); ++i) {
      char& c = word[i];
      if (c != '.') {  // letter
        if (!trie->has_next(c))
          return false;
        trie = trie->next[c];
      } else {        // dot
        for (auto& [fst, snd] : trie->next) {
          if (search(word, i + 1, snd))    // find one is okey
            return true;
        }    // cannot find anyone
        return false;
      }
    }
    return trie->eow;   // is an end of word
  }

private:
  Trie root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
