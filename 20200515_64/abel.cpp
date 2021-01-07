/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = int(grid.size());
        if (m == 0) return 0;
        int n = int(grid[0].size());
        if (n == 0) return 0;
        int d[210][210];
        memset(d, 0x3f3f3f3f, sizeof d);
        d[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {continue;}
                if (i > 0) {
                    d[i][j] = min(d[i-1][j] + grid[i][j], d[i][j]);
                }
                if (j > 0) {
                    d[i][j] = min(d[i][j], d[i][j-1] + grid[i][j]);
                }
            }
        }
        return d[m-1][n-1];
    }
};
// @lc code=end

