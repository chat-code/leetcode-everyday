#
# @lc app=leetcode id=2006 lang=python3
#
# [2006] Count Number of Pairs With Absolute Difference K
#

# @lc code=start
class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        r ={}
        c = 0
        
        for ii in nums:
            c += r.get(ii, 0)
            
            r[k + ii] = r.get(k + ii, 0) + 1
            r[ii - k] = r.get(ii - k, 0) + 1

        return c


# @lc code=end

