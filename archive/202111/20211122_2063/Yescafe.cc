class Solution {
  using ll = long long;
public:
  ll countVowels(string word) {
    ll res;
    auto len = word.length();
    
    vector<ll> prefix(len, 0);
    prefix[0] = is_vowel(word.front());

    for (int i = 1; i < len; ++i) {
      prefix[i] = prefix[i - 1] + is_vowel(word[i]) * (i + 1);
    }
    
    return accumulate(begin(prefix), end(prefix), 0LL);
  }
  
private:
  bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
