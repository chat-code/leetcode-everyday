#
# @lc app=leetcode id=1219 lang=python3
#
# [1219] Path with Maximum Gold
#

# @lc code=start

from copy import deepcopy


class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        v = []
        for _ in range(0, m):
            v.append([False] * n)

        
        def search_path(grid, v, ii, jj, c, m, n, cMax):
            c += grid[ii][jj]
            v[ii][jj] = True
            flag = False

            if ii > 0 and grid[ii-1][jj] > 0 and not v[ii-1][jj]:
                flag = True
                search_path(grid, v, ii-1, jj, c, m, n, cMax)
                v[ii-1][jj] = False

            if jj > 0 and grid[ii][jj-1] > 0 and not v[ii][jj-1]:
                flag = True
                search_path(grid, v, ii, jj-1, c, m, n, cMax)
                v[ii][jj-1] = False
             
            if ii < m - 1 and grid[ii+1][jj] > 0 and not v[ii+1][jj]:
                flag = True
                search_path(grid, v, ii+1, jj, c, m, n, cMax)
                v[ii+1][jj] = False
            
            if jj < n - 1 and grid[ii][jj+1] > 0 and not v[ii][jj+1]:
                flag = True
                search_path(grid, v, ii, jj+1, c, m, n, cMax)
                v[ii][jj+1] = False

            if not flag:
                cMax[0] = max(cMax[0], c)
            
            return c
        
        cMax = [0]
        for ii in range(0, m):
            for jj in range(0, n):
                if grid[ii][jj] > 0:
                    search_path(grid, deepcopy(v), ii, jj, 0, m, n, cMax)

        return cMax[0]

        
# @lc code=end

