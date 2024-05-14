/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 * 
 * 不斷嘗試放入元素，直到個數達到 k，把最近放入的數字去掉，再嘗試下一個數字
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
    vector<VI> result;

    void dfs(int start, int n, VI& cur, int k) {
        if(k == 0) {
            result.push_back(cur);
            return;
        }
        for (int i = start; i <= n; ++i) {
            cur.push_back(i);
            dfs(i+1, n, cur, k-1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        VI cur;
        dfs(1, n, cur, k);
        return result;
    }
};
// @lc code=end

