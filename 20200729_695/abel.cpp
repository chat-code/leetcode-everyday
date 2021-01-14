//给定一个包含了一些 0 和 1 的非空二维数组 grid 。 
//
// 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 
//0（代表水）包围着。 
//
// 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。) 
//
// 
//
// 示例 1: 
//
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,1,1,0,1,0,0,0,0,0,0,0,0],
// [0,1,0,0,1,1,0,0,1,0,1,0,0],
// [0,1,0,0,1,1,0,0,1,1,1,0,0],
// [0,0,0,0,0,0,0,0,0,0,1,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// 
//
// 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。 
//
// 示例 2: 
//
// [[0,0,0,0,0,0,0,0]] 
//
// 对于上面这个给定的矩阵, 返回 0。 
//
// 
//
// 注意: 给定的矩阵grid 的长度和宽度都不超过 50。 
// Related Topics 深度优先搜索 数组 
// 👍 412 👎 0


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
    int res, m, n;
    int vis[55][55];
    vector <VI> a;
    int dir[4][2] = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0},
    };

    void dfs(int x, int y, int &sum) {
        res = max(res, sum);
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int x1 = x + dir[i][0], y1 = y + dir[i][1];
            if (x1 < m && x1 >= 0 && y1 < n && y1 >= 0) {
                if (!vis[x1][y1] && a[x1][y1] == 1) {
                    ++sum;
                    dfs(x1, y1, sum);
                }
            }
        }
    }

    int maxAreaOfIsland(vector <vector<int>> &grid) {
        res = 0;
        a = grid;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && a[i][j]) {
                    int sum = 1;
                    dfs(i, j, sum);
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
