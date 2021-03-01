//冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。 
//
// 在加热器的加热半径范围内的每个房屋都可以获得供暖。 
//
// 现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。 
//
// 说明：所有供暖器都遵循你的半径标准，加热的半径也一样。 
//
// 
//
// 示例 1: 
//
// 
//输入: houses = [1,2,3], heaters = [2]
//输出: 1
//解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
// 
//
// 示例 2: 
//
// 
//输入: houses = [1,2,3,4], heaters = [1,4]
//输出: 1
//解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
// 
//
// 示例 3： 
//
// 
//输入：houses = [1,5], heaters = [2]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= houses.length, heaters.length <= 3 * 104 
// 1 <= houses[i], heaters[i] <= 109 
// 
// Related Topics 二分查找 
// 👍 182 👎 0

// 找到每个房子左右两边距离最近的heater，所有房子的距离最近的heater的距离最大值即为所求
// 找房子左右两边距离最近的heater，可以使用二分，利用lower_bound，找到>=x的第一个位置
// 也可以手写二分

//leetcode submit region begin(Prohibit modification and deletion)
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

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        int len = houses.size();
        VI d(len, 0x3f3f3f3f);
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int i = 0; i < len; i++) {
            auto it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            if (it == heaters.end()) {
                --it;
                d[i] = houses[i] - *it;
            } else if (it == heaters.begin()) {
                d[i] = *it - houses[i];
            } else {
                int left = *(it - 1), right = *it;
                d[i] = min(houses[i] - left, right - houses[i]);
            }
            res = max(res, d[i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
