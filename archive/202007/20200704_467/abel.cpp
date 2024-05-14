/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 * 
 * 找到以某個字母結尾的，最長的連續遞增序列的長度
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
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int d[30];
        memset(d, 0, sizeof d);
        VI a(p.size(), 0);

        int len = p.size();
        if (len <= 1) return len;

        for(int i = 0; i < len; i++) {
            a[i] = p[i] - 'a';
        }

        d[a[0]] = 1;
        int cur = 1;
        for (int i = 1; i < len; ++i) {
            int j = i - 1;
            if ((a[j] + 1) % 26 == a[i]) {
                ++cur;
                d[a[i]] = max(d[a[i]], cur);
            } else {
                cur = 1;
                d[a[i]] = max(d[a[i]], 1);
            }
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            res += d[i];
        }
        return res;
    }
};
// @lc code=end

