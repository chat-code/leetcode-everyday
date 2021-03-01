//有两种形状的瓷砖：一种是 2x1 的多米诺形，另一种是形如 "L" 的托米诺形。两种形状都可以旋转。 
//
// 
//XX  <- 多米诺
//
//XX  <- "L" 托米诺
//X
// 
//
// 给定 N 的值，有多少种方法可以平铺 2 x N 的面板？返回值 mod 10^9 + 7。 
//
// （平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，使得恰好有一个平铺有一个瓷砖占据两个正方形。） 
//
// 
//示例:
//输入: 3
//输出: 5
//解释: 
//下面列出了五种不同的方法，不同字母代表不同瓷砖：
//XYZ XXZ XYY XXY XYY
//XYZ YYZ XZZ XYY XXY 
//
// 提示： 
//
// 
// N 的范围是 [1, 1000] 
// 
//
// 
// Related Topics 动态规划 
// 👍 77 👎 0

// d1[i] 表示第 i 个位置，填满的方法数量
// d2[i] 表示第 i 个位置，有一个为空的方法数量


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

const int MOD = int(1e9 + 7);

class Solution {
public:
    long long d1[1009]{};
    long long d2[1009]{};

    int numTilings(int N) {
        d1[1] = 1;
        d1[2] = 2;
        d2[2] = 2;

        for (int i = 3; i <= N; ++i) {
            d1[i] = d1[i - 1] + d1[i - 2] + d2[i - 1];
            d1[i] %= MOD;
            d2[i] = d1[i - 2] * 2 + d2[i - 1];
            d2[i] %= MOD;
        }
        return d1[N];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
