#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reformat(string s) {
        int n = s.size();
        if (!n) return "";

        vector<char> cc, nn;
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) nn.push_back(s[i]);
            else cc.push_back(s[i]);
        }
        int m = cc.size(), k = nn.size();
        if (abs(k - m) > 1) return "";

        string res;

        if (m > k) {
            res += cc[0];
            for (int i = 0; i < k; ++i) {
                res.push_back(nn[i]);
                res.push_back(cc[i + 1]);
            }
        } else if (m < k) {
            res += nn[0];
            for (int i = 0; i < m; ++i) {
                res.push_back(cc[i]);
                res.push_back(nn[i + 1]);
            }
        } else {
            for (int i = 0; i < m; ++i) {
                res = res + cc[i] + nn[i];
            }
        }

        return res;
    }
};
