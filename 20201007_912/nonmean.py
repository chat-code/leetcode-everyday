#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#

# @lc code=start
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        def partition(nums, l, r, i):
            p = nums[i]
            nums[i], nums[r] = nums[r], nums[i]
            j = l
            while l < r:
                if nums[l] < p:
                    nums[j], nums[l] = nums[l], nums[j]
                    j += 1
                
                l += 1

            nums[j], nums[r] = nums[r], nums[j]

            return j
            

        def quickSort(nums, l, r):
            if l < r:
                i = (l + r) // 2
                p = partition(nums, l, r, i)
                
                quickSort(nums, l, p-1)
                quickSort(nums, p+1, r)
        

        quickSort(nums, 0, len(nums) - 1)

        return nums

        
# @lc code=end

