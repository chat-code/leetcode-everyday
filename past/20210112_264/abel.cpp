//编写一个程序，找出第 n 个丑数。 
//
// 丑数就是质因数只包含 2, 3, 5 的正整数。 
//
// 示例: 
//
// 输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。 
//
// 说明: 
//
// 
// 1 是丑数。 
// n 不超过1690。 
// 
// Related Topics 堆 数学 动态规划 
// 👍 472 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    int nthUglyNumber(int n) {
        map<ll, int> m;
        ll t = 1, res = 1;
        priority_queue<ll, vector<ll>, greater<ll>> q; q.push(t);
        m[1] = 1;
        while (n--) {
           res = q.top(); q.pop();
           t = res * 2; if (!m[t]) { m[t] = 1; q.push(t); }
           t = res * 3; if (!m[t]) { m[t] = 1; q.push(t); }
           t = res * 5; if (!m[t]) { m[t] = 1; q.push(t); }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
