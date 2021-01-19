/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 * 
 * 蓄水池取樣
 * 假设当前正要读取第n个数据，则我们以1/n的概率留下该数据，否则留下前n-1个数据中的一个。
 * 其實還沒有怎麼理解……
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

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    vector<int> a;
    Solution(vector<int>& nums) {
        a = nums;
    }
    
    int pick(int target) {
        int r = rand();
        int n = 0, res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == target) {
                ++n;
                if (r % n == 0) {
                    res = i;
                }
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

