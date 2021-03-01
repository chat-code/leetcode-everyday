/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    VI add(VI& a, VI& b) {
        VI c;
        int t = 0;
        for (int i = 0; i < a.size() || i < b.size(); ++i) {
            if (i < a.size()) t += a[i];
            if (i < b.size()) t += b[i];
            c.push_back((t + 2) % 2);
            t /= 2;
        }
        if (t) c.push_back(t);
        return c;
    }
    string addBinary(string a, string b) {
        VI A, B;
        for (int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
        for (int i = b.size() - 1; i >= 0; --i) B.push_back(b[i] - '0');
        VI C = add(A, B);
        string r;
        for (int i = C.size() - 1; i >= 0; --i) r = r + char('0' + C[i]);
        return r;
    }
};
// @lc code=end

