/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
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
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    int strStr(string a, string b) {
        int lena = a.length(), lenb = b.length();
        if (lenb == 0) return 0;
        for (int i = 0; i <= lena-lenb; ++i) {
            int j = 0;
            int k = i;
            while (k < lena && j < lenb && a[k] == b[j]) {
                ++k;
                ++j;
            }
            if (j == lenb) return i;
        }
        return -1;
    }
};
// @lc code=end

