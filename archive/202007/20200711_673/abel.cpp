//给定一个未排序的整数数组，找到最长递增子序列的个数。 
//
// 示例 1: 
//
// 
//输入: [1,3,5,4,7]
//输出: 2
//解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
// 
//
// 示例 2: 
//
// 
//输入: [2,2,2,2,2]
//输出: 5
//解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
// 
//
// 注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。 
// Related Topics 动态规划 
// 👍 256 👎 0

// 修改一下最长子序列长度的做法即可


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
    int d[2020], c[2020];

    int findNumberOfLIS(vector<int> &a) {
        int len = a.size();
        memset(d, 0, sizeof(d));
        memset(c, 0, sizeof(c));
        int maxlen = 1, res = 0;
        for (int i = 0; i < len; ++i) d[i] = c[i] = 1;
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i] > a[j]) {
                    if (d[j] + 1 > d[i]) {
                        d[i] = d[j] + 1;
                        maxlen = max(maxlen, d[i]);
                        c[i] = c[j];
                    } else if (d[j] + 1 == d[i]) {
                        c[i] += c[j];
                    }
                }
            }
        }
        for (int i = 0; i < len; ++i) {
            if (maxlen == d[i]) {
                res += c[i];
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
