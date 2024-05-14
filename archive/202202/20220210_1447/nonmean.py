#
# @lc app=leetcode id=1447 lang=python3
#
# [1447] Simplified Fractions
#

# @lc code=start
class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        s = []

        def getMaxFactor(a, b):
            i = max(a, b)
            j = min(a, b)

            while i % j != 0:
                i, j = j, i%j
            
            return j

        for ii in range(2, n+1):
            for jj in range(1, ii):
                if getMaxFactor(ii, jj) == 1:
                    s.append("%d/%d" %(jj, ii))

        return s

        
# @lc code=end

