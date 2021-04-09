class Solution {
public:
    bool detectCapitalUse(string word) {
        if (!word.size()) return true;
        int n = word.size();
        bool cap = isupper(word[0]);
        if (cap) {
            if (n == 1) return true;
            if (isupper(word[1])) {
                for (int i = 2; i < n; ++i)
                    if (islower(word[i])) return false;
                return true;
            } else {
                for (int i = 2; i < n; ++i)
                    if (isupper(word[i])) return false;
                return true;
            }
        } else {
            for (int i = 1; i < n; ++i)
                if (isupper(word[i])) return false;
            return true;
        }
    }
};
