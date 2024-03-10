#
# @lc app=leetcode id=172 lang=python3
#
# [172] Factorial Trailing Zeroes
#

# @lc code=start
class Solution:
    def trailingZeroes(self, n: int) -> int:

        def checkFactor(m, n):
            c = 0

            while m >= n and m % n == 0:
                c += 1
                m = m / n
            
            return c
        
        a1 = 0
        a2 = 0

        for ii in range(2, n+1):
            a1 += checkFactor(ii, 2)
            a2 += checkFactor(ii, 5)

        return min(a1, a2)
      
        
# @lc code=end

