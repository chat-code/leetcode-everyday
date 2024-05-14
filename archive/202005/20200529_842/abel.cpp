/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] 将数组拆分成斐波那契序列
 * 
 * DFS
 * 幾處剪枝：
 * 1. 首位是 0，不能繼續擴展
 * 2. 當前擴展的數字超過 INT_MAX，停止擴展
 * 3. 當前擴展的數字超過前兩個數字之和，停止擴展
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    using VI = vector<int>;

    bool dfs(int prev, int sum, int index, VI& res, VI& a) {
        int len = a.size();
        if (index >= len) return res.size() >= 3;
        long long cur = 0;
        for (int i = index; i < len; ++i) {
            cur = cur * 10 + a[i];
            // at most 1 preceding 0
            // NOTE: if the first position is 0, then don't extend
            if (a[index] == 0 && i > index) return false;
            if (cur > INT_MAX) return false;
            if (res.size() >= 2) {
                if (cur > sum) return false;
                else if (cur < sum) continue;
            }
            res.push_back(cur);
            bool tmp = dfs(int(cur), int(cur + prev), i+1, res, a);
            if (tmp) return true;
            else {
                res.pop_back();
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string S) {
        VI a(S.size(), 0);
        for (int i = 0; i < S.size(); i++) {
            a[i] = S[i] - '0';
        }
        VI res;
        dfs(0, 0, 0, res, a);
        return res;
    }
};
// @lc code=end

