#
# @lc app=leetcode id=2022 lang=python3
#
# [2022] Convert 1D Array Into 2D Array
#

# @lc code=start
class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        p = len(original)
        res = []

        if p != m * n:
            return res
        
        if m == 1:
            res.append(original)
            return res

        for ii in range(0, m):
            res.append(original[n*ii:n*ii+n])

        return res


# @lc code=end

