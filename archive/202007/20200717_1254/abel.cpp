/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 * 
 * 兩遍 DFS
 * 第一遍把邊緣的 0 變成 1
 * 第二遍尋找島嶼的個數
 */

// @lc code=start

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
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    int m, n;
    int vis[110][110];
    int dir[4][2] = { {0,1}, {1, 0}, {0, -1},{-1, 0}};
    vector<VI> a;
    int res;

    void dfs(int x, int y) {
        vis[x][y] = 1;
        a[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int x1 = x + dir[i][0], y1 = y + dir[i][1];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n) {
                if (!vis[x1][y1] && a[x1][y1] == 0) {
                    dfs(x1, y1);
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        a = grid;
        m = grid.size();
        n = grid[0].size();
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (!vis[i][j] && grid[i][j] == 0) {
                        dfs(i, j);
                    }
                }
            }
        }
        res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 0) {
                    ++res;
                    dfs(i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end

