using ll = long long;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
      ll n = 0;
      for (auto &c : s) {
        if (isdigit(c)) n *= (c - '0');
        else ++n;
      }

      for (int i = s.size() - 1; i >= 0; --i) {
        if (isdigit(s[i])) {
          int x = s[i] - '0';
          
          n /= x;
          k %= n;
          if (!k) k = n;
        } else {
          if (k == n) return string(1, s[i]);
          n--;
        }
      }

      return "";
    }
};
