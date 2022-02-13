#
# @lc app=leetcode id=2150 lang=python3
#
# [2150] Find All Lonely Numbers in the Array
#

# @lc code=start
class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        if len(nums) == 1:
            return nums

        nums.sort()

        res = []
        for ii in range(0, len(nums)):
            if ii < len(nums) - 1:
                if nums[ii] == nums[ii+1] or nums[ii] == nums[ii+1] - 1:
                    continue
            
            if ii > 0:
                if nums[ii] == nums[ii-1] or nums[ii] == nums[ii-1] + 1:
                    continue

            res.append(nums[ii])

        return res

        
# @lc code=end

