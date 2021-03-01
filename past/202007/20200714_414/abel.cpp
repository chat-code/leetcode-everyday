//给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。 
//
// 
//
// 示例 1： 
//
// 
//输入：[3, 2, 1]
//输出：1
//解释：第三大的数是 1 。 
//
// 示例 2： 
//
// 
//输入：[1, 2]
//输出：2
//解释：第三大的数不存在, 所以返回最大的数 2 。
// 
//
// 示例 3： 
//
// 
//输入：[2, 2, 3, 1]
//输出：1
//解释：注意，要求返回第三大的数，是指第三大且唯一出现的数。
//存在两个值为2的数，它们都排第二。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 104 
// 231 <= nums[i] <= 231 - 1 
// 
//
// 
//
// 进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？ 
// Related Topics 数组 
// 👍 197 👎 0


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
#include <queue>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        else if (len == 2) return max(nums[0], nums[1]);
        priority_queue<int, VI, greater<int>> que;
        set<int> ss;
        int res = 0;

        for (int i = 0; i < len; i++) {
            if (que.empty()) {
                que.push(nums[i]);
                ss.insert(nums[i]);
            } else {
                if (ss.find(nums[i]) != ss.end()) continue;

                int t = que.top();
                if (nums[i] > t) {
                    ss.insert(nums[i]);
                    que.push(nums[i]);
                    if (que.size() > 3) {
                        que.pop();
                        ss.erase(t);
                    }
                } else if (nums[i] < t) {
                    if (que.size() < 3) {
                        ss.insert(nums[i]);
                        que.push(nums[i]);
                    }
                }
            }
        }
        if (que.size() == 3) { res = que.top(); }
        else {
            while (!que.empty()) {
                res = que.top();
                que.pop();
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
