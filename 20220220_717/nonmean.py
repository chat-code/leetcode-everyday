#
# @lc app=leetcode id=717 lang=python3
#
# [717] 1-bit and 2-bit Characters
#

# @lc code=start
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        ii = 0

        while ii < len(bits):
            k = 1 if bits[ii] == 0 else 2
            ii += k
        
        return k == 1

        
# @lc code=end

