// 比较蠢的3层循环- -。。。。
class Solution {
    map<char, vector<string>> imap = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}}
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res = imap[digits[0]];
        if (digits.size() == 0) return vector<string>();
        for (int i = 1; i < digits.size(); ++i) {
            res = cartesianProduct(res, imap[digits[i]]);
        }
        return res;
    }


    vector<string> cartesianProduct (const vector<string> &a, const vector<string> &b) {
        vector<string> res;
        for (int i = 0; i < a.size(); i++) {
            cout << "i" << i << endl;
            for (int j = 0; j < b.size(); j++) {
                cout << "j" << j << endl;
                res.push_back(a[i] + b[j]);
            }
        }
        return res;
    }
};