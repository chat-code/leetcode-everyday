#
# @lc app=leetcode id=1380 lang=python3
#
# [1380] Lucky Numbers in a Matrix
#

# @lc code=start
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        r = [1e6] * len(matrix)
        c = [-1] * len(matrix[0])
        
        res = []

        for ii in range(0, len(matrix)):    
            for jj in range(0, len(matrix[0])):
                r[ii] = min(r[ii], matrix[ii][jj])
                c[jj] = max(c[jj], matrix[ii][jj])
            
        for ii in range(0, len(matrix)):
            for jj in range(0, len(matrix[0])):
                if r[ii] == c[jj]:
                    res.append(r[ii])

        return res    

        
# @lc code=end

