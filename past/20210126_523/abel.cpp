//给定一个包含 非负数 的数组和一个目标 整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，且总和为 k 的倍数，即总和为 n*k，其
//中 n 也是一个整数。 
//
// 
//
// 示例 1： 
//
// 输入：[23,2,4,6,7], k = 6
//输出：True
//解释：[2,4] 是一个大小为 2 的子数组，并且和为 6。
// 
//
// 示例 2： 
//
// 输入：[23,2,6,4,7], k = 6
//输出：True
//解释：[23,2,6,4,7]是大小为 5 的子数组，并且和为 42。
// 
//
// 
//
// 说明： 
//
// 
// 数组的长度不会超过 10,000 。 
// 你可以认为所有数字总和在 32 位有符号整数范围内。 
// 
// Related Topics 数学 动态规划 
// 👍 214 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        map<int, int> s;
        s[0] = -1;
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = (pre[i] + nums[i]);
            if (k) pre[i + 1] %= k;
            if (s.find(pre[i + 1]) != s.end()) {
                if (i - s[pre[i + 1]] > 1) return true;
            } else
                s[pre[i + 1]] = i;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
