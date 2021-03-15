#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string interpret(string s) {
        string res;
        int n = s.size();
        if (!n) return res;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'G') res += s[i];
            else if (s[i] == '(' && s[i + 1] == ')') {
                res += 'o';
                i++;
            } else if (s[i] == '(' && s[i + 1] == 'a') {
                res += "al";
                i += 3;
            }
        }
        return res;
    }
};
