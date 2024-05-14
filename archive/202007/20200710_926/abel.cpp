//如果一个由 '0' 和 '1' 组成的字符串，是以一些 '0'（可能没有 '0'）后面跟着一些 '1'（也可能没有 '1'）的形式组成的，那么该字符串是单调
//递增的。 
//
// 我们给出一个由字符 '0' 和 '1' 组成的字符串 S，我们可以将任何 '0' 翻转为 '1' 或者将 '1' 翻转为 '0'。 
//
// 返回使 S 单调递增的最小翻转次数。 
//
// 
//
// 示例 1： 
//
// 输入："00110"
//输出：1
//解释：我们翻转最后一位得到 00111.
// 
//
// 示例 2： 
//
// 输入："010110"
//输出：2
//解释：我们翻转得到 011111，或者是 000111。
// 
//
// 示例 3： 
//
// 输入："00011000"
//输出：2
//解释：我们翻转得到 00000000。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= S.length <= 20000 
// S 中只包含字符 '0' 和 '1' 
// 
// Related Topics 数组 
// 👍 77 👎 0

// 左边只可能是0，右边只可能是1，利用这个特性
// 枚举每个位置，如果左边全部变成0，右边全部变成1，一共需要多少次操作；可以这样计算：左边有多少个1需要变成0，右边有多少个0需要变成1，
// 因此只需要预处理出每个位置左边有多少个1即可。前缀和。
// 注意边界情况：全部为1，全部为0


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
    int minFlipsMonoIncr(string S) {
        int len = S.size();
        VI d(len, 0);
        int sum = 0;
        for (int i = 0; i < len; i++) {
            int t = (S[i] == '1');
            if (i > 0) {
                d[i] = d[i - 1] + t;
            } else {
                d[i] = t;
            }
            sum += t;
        }
        int res = len * 2;
        for (int i = 0; i <= len; i++) {
            int left, right;
            if (i == 0) {
                left = 0;
                right = len - sum;
            } else {
                left = d[i - 1];
                right = (len - i) - (sum - left);
            }
            res = min(res, left + right);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
