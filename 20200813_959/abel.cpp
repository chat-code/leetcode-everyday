//在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。 
//
// （请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。 
//
// 返回区域的数目。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入：
//[
//  " /",
//  "/ "
//]
//输出：2
//解释：2x2 网格如下：
// 
//
// 示例 2： 
//
// 输入：
//[
//  " /",
//  "  "
//]
//输出：1
//解释：2x2 网格如下：
// 
//
// 示例 3： 
//
// 输入：
//[
//  "\\/",
//  "/\\"
//]
//输出：4
//解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
//2x2 网格如下：
// 
//
// 示例 4： 
//
// 输入：
//[
//  "/\\",
//  "\\/"
//]
//输出：5
//解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
//2x2 网格如下：
// 
//
// 示例 5： 
//
// 输入：
//[
//  "//",
//  "/ "
//]
//输出：3
//解释：2x2 网格如下：
//
// 
//
// 
//
// 提示： 
//
// 
// 1 <= grid.length == grid[0].length <= 30 
// grid[i][j] 是 '/'、'\'、或 ' '。 
// 
// Related Topics 深度优先搜索 并查集 图 
// 👍 118 👎 0


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

int sz[3900], fa[3900];

int Find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = Find(fa[x]);
}

void Union(int x, int y) {
    int rx = Find(x), ry = Find(y);
    if (rx == ry) return;
    if (sz[rx] < sz[ry]) swap(rx, ry);
    fa[ry] = rx;
    sz[rx] += sz[ry];
}

class Solution {
public:
    int regionsBySlashes(vector <string> &a) {
        int n = a.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = i * n * 4 + j * 4;
                for (int k = 0; k < 4; ++k) {
                    fa[k + base] = k + base;
                    sz[k + base] = 1;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = i * n * 4 + j * 4;
                if (a[i][j] == ' ') {
                    for (int k = 0; k <= 2; k++) {
                        Union(base + k, base + k + 1);
                    }
                } else if (a[i][j] == '/') {
                    Union(base, base + 2);
                    Union(base + 1, base + 3);
                } else if (a[i][j] == '\\') {
                    Union(base, base + 1);
                    Union(base + 2, base + 3);
                }
                if (j) {
                    // left
                    // 2 -> 1
                    Union(base + 2, base - 4 + 1);
                }
                if (i) {
                    // 0 -> 3
                    Union(base, base - 4 * n + 3);
                }
            }
        }

        set<int> ss;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = i * n * 4 + j * 4;
                for (int k = 0; k < 4; ++k) {
                    int ro = Find(k + base);
                    ss.insert(ro);
                }
            }
        }
        return ss.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
