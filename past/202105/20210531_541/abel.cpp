#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        bool flag = true;
        for (int i = 0, j = 0; i < n; ++i) {
            j = min(i + k, n);
            j--;

            if (flag) {
                for (int k1 = i, k2 = j; k1 < k2; k1++, k2--) {
                    swap(s[k1], s[k2]);
                }
                i = j;
                flag = false;
            } else {
                i = j;
                flag = true;
            }
        }
        return s;
    }
};