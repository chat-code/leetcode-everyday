//假设有从 1 到 N 的 N 个整数，如果从这 N 个数字中成功构造出一个数组，使得数组的第 i 位 (1 <= i <= N) 满足如下两个条件中的一个，
//我们就称这个数组为一个优美的排列。条件： 
//
// 
// 第 i 位的数字能被 i 整除 
// i 能被第 i 位上的数字整除 
// 
//
// 现在给定一个整数 N，请问可以构造多少个优美的排列？ 
//
// 示例1: 
//
// 
//输入: 2
//输出: 2
//解释: 
//
//第 1 个优美的排列是 [1, 2]:
//  第 1 个位置（i=1）上的数字是1，1能被 i（i=1）整除
//  第 2 个位置（i=2）上的数字是2，2能被 i（i=2）整除
//
//第 2 个优美的排列是 [2, 1]:
//  第 1 个位置（i=1）上的数字是2，2能被 i（i=1）整除
//  第 2 个位置（i=2）上的数字是1，i（i=2）能被 1 整除
// 
//
// 说明: 
//
// 
// N 是一个正整数，并且不会超过15。 
// 
// Related Topics 深度优先搜索 回溯算法 
// 👍 120 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

const int N = 20;
int a[N], vis[N];

class Solution {
public:
    int res, n;

    void dfs(int k) {
        if (k == n + 1) {
            ++res;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && (i % k == 0 || k % i == 0)) {
                vis[i] = 1;
                dfs(k + 1);
                vis[i] = 0;
            }
        }
    }

    int countArrangement(int _n) {
        res = 0;
        n = _n;
        memset(vis, 0, sizeof vis);
        dfs(1);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
