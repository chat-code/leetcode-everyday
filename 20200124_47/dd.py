from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)

        nums.sort(reverse=True)
        s = 1
        for i in range(1, n + 1):
            s *= i

        def nt():
            yield nums[:]
            for ss in range(s):
                for i in range(1, n):
                    if nums[i] < nums[i - 1]:
                        print(nums)
                        e = 0
                        for j in range(0, i // 2):
                            nums[j], nums[i - 1 - j] = nums[i - 1 - j], nums[j]
                        for j in range(i):
                            if nums[j] > nums[i]:
                                e = j
                        nums[e], nums[i] = nums[i], nums[e]
                        yield nums[:]
                        break

        return [i for i in nt()]