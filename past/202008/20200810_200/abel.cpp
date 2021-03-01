//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 
// 👍 941 👎 0


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

int vis[310][310];
int dir[4][2] = {{0,  1},
                 {1,  0},
                 {0,  -1},
                 {-1, 0}};

class Solution {
public:
    int m, n;
    vector <vector<char>> a;

    void dfs(int x, int y) {
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int x1 = x + dir[i][0], y1 = y + dir[i][1];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n) {
                if (!vis[x1][y1] && a[x1][y1] == '1') {
                    dfs(x1, y1);
                }
            }
        }
    }

    int numIslands(vector <vector<char>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        m = grid.size(), n = grid[0].size();
        memset(vis, 0, sizeof vis);
        a = grid;

        int res{0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && a[i][j] == '1') {
                    dfs(i, j);
                    ++res;
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
