//给你两个整数数组 source 和 target ，长度都是 n 。还有一个数组 allowedSwaps ，其中每个 allowedSwaps[i] = 
//[ai, bi] 表示你可以交换数组 source 中下标为 ai 和 bi（下标从 0 开始）的两个元素。注意，你可以按 任意 顺序 多次 交换一对特定下标指
//向的元素。 
//
// 相同长度的两个数组 source 和 target 间的 汉明距离 是元素不同的下标数量。形式上，其值等于满足 source[i] != target[i
//] （下标从 0 开始）的下标 i（0 <= i <= n-1）的数量。 
//
// 在对数组 source 执行 任意 数量的交换操作后，返回 source 和 target 间的 最小汉明距离 。 
//
// 
//
// 示例 1： 
//
// 输入：source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
//输出：1
//解释：source 可以按下述方式转换：
//- 交换下标 0 和 1 指向的元素：source = [2,1,3,4]
//- 交换下标 2 和 3 指向的元素：source = [2,1,4,3]
//source 和 target 间的汉明距离是 1 ，二者有 1 处元素不同，在下标 3 。
// 
//
// 示例 2： 
//
// 输入：source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
//输出：2
//解释：不能对 source 执行交换操作。
//source 和 target 间的汉明距离是 2 ，二者有 2 处元素不同，在下标 1 和下标 2 。 
//
// 示例 3： 
//
// 输入：source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1
//,3],[1,4]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// n == source.length == target.length 
// 1 <= n <= 105 
// 1 <= source[i], target[i] <= 105 
// 0 <= allowedSwaps.length <= 105 
// allowedSwaps[i].length == 2 
// 0 <= ai, bi <= n - 1 
// ai != bi 
// 
// Related Topics 贪心算法 深度优先搜索 并查集 
// 👍 24 👎 0


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

const int N = 100009;
int fa[N], sz[N];

int Find(int x) {
    if (fa[x] == x) return x;
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
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector <vector<int>> &allowedSwaps) {
        int n = allowedSwaps.size();
        for (int i = 0; i < target.size(); i++) {
            fa[i] = i;
            sz[i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            Union(allowedSwaps[i][0], allowedSwaps[i][1]);
        }
        map<int, multiset<int>> m;
        for (int i = 0; i < source.size(); i++) {
            int rx = Find(i);
            m[rx].insert(source[i]);
        }
        int res = 0;
        for (int i = 0; i < target.size(); i++) {
            auto &x = m[Find(i)];
            auto it = x.find(target[i]);
            if (it != x.end()) {
                x.erase(it);
            } else {
                ++res;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
