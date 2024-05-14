//请你帮忙设计一个程序，用来找出第 n 个丑数。 
//
// 丑数是可以被 a 或 b 或 c 整除的 正整数。 
//
// 
//
// 示例 1： 
//
// 输入：n = 3, a = 2, b = 3, c = 5
//输出：4
//解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。 
//
// 示例 2： 
//
// 输入：n = 4, a = 2, b = 3, c = 4
//输出：6
//解释：丑数序列为 2, 3, 4, 6, 8, 9, 10, 12... 其中第 4 个是 6。
// 
//
// 示例 3： 
//
// 输入：n = 5, a = 2, b = 11, c = 13
//输出：10
//解释：丑数序列为 2, 4, 6, 8, 10, 11, 12, 13... 其中第 5 个是 10。
// 
//
// 示例 4： 
//
// 输入：n = 1000000000, a = 2, b = 217983653, c = 336916467
//输出：1999999984
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n, a, b, c <= 10^9 
// 1 <= a * b * c <= 10^18 
// 本题结果在 [1, 2 * 10^9] 的范围内 
// 
// Related Topics 数学 二分查找 
// 👍 61 👎 0


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
using LL = long long;

class Solution {
public:
    int a1, b1, c1;

    LL gcd(LL a, LL b) {
        if (a < b) swap(a, b);
        if (b == 0) return a;
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }

    LL mtim(LL a, LL b) {
        return a * b / gcd(a, b);
    }

    int cx(int x) {
        LL tmp = mtim(b1, c1);
        return (x / a1 + x / b1 + x / c1) - (x / mtim(a1, b1) + x / tmp + x / mtim(a1, c1)) +
               (x / mtim(a1, tmp));
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        a1 = a;
        b1 = b;
        c1 = c;
        long long low = min(a, min(b, c)), high = low * n, mid;
        while (low < high) {
            mid = (high - low) / 2 + low;

            int tmp{cx(mid)};
            if (tmp == n) {
                low = mid;
                break;
            } else if (tmp > n) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low -= min(low % a1, min(low % b1, low % c1));
        return low;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution a;
    a.nthUglyNumber(1000000000, 2, 217983653, 336916467);
    return 0;
}
