//给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。 
//
// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。 
//
// 示例: 
//
// X X X X
//X O O X
//X X O X
//X O X X
// 
//
// 运行你的函数后，矩阵变为： 
//
// X X X X
//X X X X
//X X X X
//X O X X
// 
//
// 解释: 
//
// 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被
//填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。 
// Related Topics 深度优先搜索 广度优先搜索 并查集 
// 👍 455 👎 0


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
    vector <vector<char>> a;
    vector <VI> vis, b;
    int m, n;
    int dir[4][2] = {{0,  1},
                     {0,  -1},
                     {1,  0},
                     {-1, 0}};

    void dfs(int x, int y, int f) {
        vis[x][y] = 1;
        if (f) a[x][y] = 'X';
        for (int i = 0; i < 4; ++i) {
            int x1 = x + dir[i][0], y1 = y + dir[i][1];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n) {
                if (!vis[x1][y1] && a[x1][y1] == 'O') {
                    dfs(x1, y1, f);
                }
            }
        }
    }

    void solve(vector <vector<char>> &board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        a = board;
        m = a.size(), n = a[0].size();
        vector <VI> _vis(m, VI(n, 0));
        vis = _vis;
        vector <VI> _b(m, VI(n, 0));
        b = _b;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if (!vis[i][j] && a[i][j] == 'O')
                        dfs(i, j, 0);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && a[i][j] == 'O')
                    dfs(i, j, 1);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j)
                board[i][j] = a[i][j];
        }
        return;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
