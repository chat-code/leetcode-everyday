#
# @lc app=leetcode id=2154 lang=python3
#
# [2154] Keep Multiplying Found Values by Two
#

# @lc code=start
class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        for ii in range(0, len(nums)):
            if nums[ii] % original == 0:
                nums[ii] = nums[ii] // original
            else:
                nums[ii] = -1

        nums.sort()

        c = 0.5
        for ii in nums:
            if ii == c * 2:
                c = ii
        
        return int(original * (c * 2))

        
# @lc code=end

