//对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。 
//
// 给定一个 整数 n， 如果是完美数，返回 true，否则返回 false 
//
// 
//
// 示例 1： 
//
// 输入：28
//输出：True
//解释：28 = 1 + 2 + 4 + 7 + 14
//1, 2, 4, 7, 和 14 是 28 的所有正因子。 
//
// 示例 2： 
//
// 输入：num = 6
//输出：true
// 
//
// 示例 3： 
//
// 输入：num = 496
//输出：true
// 
//
// 示例 4： 
//
// 输入：num = 8128
//输出：true
// 
//
// 示例 5： 
//
// 输入：num = 2
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= num <= 108 
// 
// Related Topics 数学 
// 👍 81 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int n = num;
        map<int, int> primes;
        for (int i = 2; i <= num / i; ++i) {
            while (num % i == 0) {
                ++primes[i];
                num /= i;
            }
        }
        if (num > 1) ++primes[num];

        int sum = 1;
        for (auto &prime : primes) {
            int p = prime.first, q = prime.second;
            int t = 1;
            while (q--) t = t * p + 1;
            sum *= t;
        }
        sum -= n;
        return sum == n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
