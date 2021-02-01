/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 *
 * [1734] 解码异或后的排列
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
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int sum = 0, sum1 = 0;
        for (int i = 0; i <= n-2; i += 2) sum ^= encoded[i];
        for (int i = 1; i <= n; ++i) sum1 ^= i;
        int an = sum ^ sum1;

        vector<int> res1(n + 1, 0);
        res1[n] = an;
        for (int i = n; i > 1; --i) { 
            res1[i-1] = res1[i] ^ encoded[i-2];
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            res[i] = res1[i + 1];
        }
        return res;
    }
};
// @lc code=end
