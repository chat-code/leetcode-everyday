#
# @lc app=leetcode id=1748 lang=python3
#
# [1748] Sum of Unique Elements
#

# @lc code=start

class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        k = [0] * 101
        kMax = 0

        for ii in nums:
            kMax = max(kMax, ii)
            if k[ii] > 0:
                k[ii] = -1
            elif k[ii] == 0:
                k[ii] = ii

        c = 0
        for ii in range(0, kMax + 1):
            if k[ii] > 0:
                c += k[ii]

        return c

        
# @lc code=end

