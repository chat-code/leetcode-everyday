from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)

        nums.reverse()
        for i in range(1, n):
            if nums[i] < nums[i - 1]:
                e = 0
                for j in range(0, i // 2):
                    nums[j], nums[i - 1 - j] = nums[i - 1 - j], nums[j]
                for j in range(i):
                    if nums[j] > nums[i]:
                        e = j
                nums[e], nums[i] = nums[i], nums[e]
                break
        else:
            nums.reverse()
        nums.reverse()
        return nums
