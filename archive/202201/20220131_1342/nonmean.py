#
# @lc app=leetcode id=1342 lang=python3
#
# [1342] Number of Steps to Reduce a Number to Zero
#

# @lc code=start
class Solution:
    def numberOfSteps(self, num: int) -> int:
        c = 0
        while num > 0:
            p = num % 2
            num = num // 2

            if p > 0 and num > 0:
                c += 2
            else:
                c += 1
            
        return c
        
        
# @lc code=end

