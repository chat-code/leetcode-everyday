#
# @lc app=leetcode id=1706 lang=python3
#
# [1706] Where Will the Ball Fall
#

# @lc code=start
class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        def dropBall(grid, m, n, q):
            for ii in range(0, m):
                if grid[ii][q] == 1:
                    if q < n - 1:
                        if grid[ii][q+1] == -1:
                            return -1
                        else:
                            q += 1

                    else:
                        return -1 
                    
                elif grid[ii][q] == -1:
                    if q > 0:
                        if grid[ii][q-1] == 1:
                            return -1
                        else:
                            q -= 1
                    else:
                        return -1

            return q

        m = len(grid)
        n = len(grid[0])
        res = []

        for ii in range(0, n):
            res.append(dropBall(grid, m, n, ii))

        return res


# @lc code=end

