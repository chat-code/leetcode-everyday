#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string reorderSpaces(string s) {
        string res;
        int cnt = 0, n = s.size();

        for (int i = 0; i < n; ++i)
            if (isspace(s[i])) cnt++;

        stringstream ss(s);
        vector<string> sw;
        string cur;

        while (ss >> cur) {
            sw.push_back(cur);
        }

        int k = 0, rem = 0;
        if (sw.size() > 1) {
            k = cnt / (sw.size() - 1);
            rem = cnt - (k * (sw.size() - 1));
        } else {
            rem = cnt;
        }
        string sp(k, ' '), sp1(rem, ' ');

        int m = sw.size();
        for (int i = 0; i < m; ++i) {
            res += sw[i];
            if (i != m - 1) {
                res += sp;
            }
        }
        res += sp1;
        return res;
    }
};
