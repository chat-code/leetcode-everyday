#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        int st[26] {};
        for (int i = 0; i < allowed.size(); ++i)
            st[allowed[i] - 'a']++;
        for (auto &x : words) {
            bool flag = true;
            for (int i = 0; i < x.size(); ++i)
                if (st[x[i] - 'a'] == 0) {
                    flag = false;
                    break;
                }
            res += flag;
        }
        return res;
    }
};
