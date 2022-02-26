#
# @lc app=leetcode id=2016 lang=python3
#
# [2016] Maximum Difference Between Increasing Elements
#

# @lc code=start
class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        s = [nums[0]]
        l = [nums[-1]]

        k = len(nums) - 1

        for ii in range(1, k):
            s.append(min(s[-1], nums[ii]))
            l.append(max(l[-1], nums[k - ii]))
        
        m = 0
        n = 0
        for ii in range(0, k):
            n = l[k - ii - 1] - s[ii]

            if n == 0:
                continue
            elif n > m:
                m = n

        return m if m > 0 else -1

        
# @lc code=end

