#
# @lc app=leetcode id=2155 lang=python3
#
# [2155] All Divisions With the Highest Score of a Binary Array
#

# @lc code=start
class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        r = [0]
        k = [0]

        for ii in range(0, len(nums)):
            if nums[ii] == 0:
                r.append(r[-1] + 1)
                k.append(k[-1])
            else:
                k.append(k[-1] + 1)
                r.append(r[-1])
        
        cMax = -1
        m = []

        for ii in range(0, len(r)):
            c = r[ii] + (k[-1] - k[ii])

            if c > cMax:
                cMax = c
                m = [ii]
            elif c == cMax:
                m.append(ii)
        
        return m

        
# @lc code=end

