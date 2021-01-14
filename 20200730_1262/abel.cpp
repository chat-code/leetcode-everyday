/*
 * @lc app=leetcode.cn id=1262 lang=cpp
 *
 * [1262] 可被三整除的最大和
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
    int d[10009*4][3];
    int maxSumDivThree(vector<int>& a) {
        int len = a.size();
        for (int i = 0; i < len; i++) {
            d[i][0] = d[i][1] = d[i][2] = -0x3f3f3f3f;
        }
        d[0][a[0]%3] = a[0];

        for (int i = 1; i < len; ++i) {
            int r = a[i] % 3;
            if (r == 0) {
                d[i][0] = max(d[i-1][0] + a[i], max(d[i-1][0], a[i]));
                d[i][1] = max(d[i-1][1] + a[i], d[i-1][1]);
                d[i][2] = max(d[i-1][2] + a[i], d[i-1][2]);
            } else if (r == 1) {
                d[i][0] = max(d[i-1][2] + a[i], d[i-1][0]);
                d[i][1] = max(d[i-1][0] + a[i], max(d[i-1][1], a[i]));
                d[i][2] = max(d[i-1][1] + a[i], d[i-1][2]);
            } else {
                d[i][0] = max(d[i-1][1] + a[i], d[i-1][0]);
                d[i][1] = max(d[i-1][2] + a[i], d[i-1][1]);
                d[i][2] = max(d[i-1][0] + a[i], max(d[i-1][2], a[i]));
            }
        }
        return (d[len-1][0] == -0x3f3f3f3f ? 0 : d[len-1][0]);
    }
};
// @lc code=end

