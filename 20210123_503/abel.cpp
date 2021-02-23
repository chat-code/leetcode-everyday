//给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第
//一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。 
//
// 示例 1: 
//
// 
//输入: [1,2,1]
//输出: [2,-1,2]
//解释: 第一个 1 的下一个更大的数是 2；
//数字 2 找不到下一个更大的数； 
//第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
// 
//
// 注意: 输入数组的长度不会超过 10000。 
// Related Topics 栈 
// 👍 261 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
const int N = 10010;
int stk[N];

class Solution {
public:
    using VI = vector<int>;

    vector<int> nextGreaterElements(vector<int>& nums) {
        VI a(nums.begin(), nums.end());
        for (auto &x: nums) a.push_back(x);
        int tt = 0;

        VI res;
        int n = nums.size();
        for (int i = 2 * n - 1; i >= 0; --i) {
            while (tt && a[stk[tt]] <= a[i]) {
                --tt;
            }
            if (i < n) {
                if (tt == 0) {
                    res.push_back(-1);
                } else {
                    res.push_back(a[stk[tt]]);
                }
            }
            stk[++tt] = i;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
