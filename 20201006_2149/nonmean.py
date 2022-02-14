#
# @lc app=leetcode id=2149 lang=python3
#
# [2149] Rearrange Array Elements by Sign
#

# @lc code=start
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        ii = 0
        jj = 0

        m = [0] * int(len(nums) / 2)
        n = [0] * int(len(nums) / 2)

        for kk in nums:
            if kk > 0:
                m[ii] = kk
                ii += 1
            else:
                n[jj] = kk
                jj += 1

        
        for ii in range(0, len(m)):
            nums[2 * ii] = m[ii]
            nums[2 * ii + 1] = n[ii]

        return nums

        
# @lc code=end

