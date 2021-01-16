/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, prod = nums[0], sum {0};
        size_t len {nums.size()};
        while (j < len && i < len) {
            if (prod < k) {
                ++j;
                sum += (j - i);
                if (j < len) prod *= nums[j];
            } else {
                prod /= nums[i];
                ++i;
                if (i > j) {
                    j = i;
                    if (j < len)
                        prod = nums[j];
                }
            }
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution a;
    VI v{1,2,3};
    int k{0};
    cout << a.numSubarrayProductLessThanK(v, k) << endl;
    return 0;
}
