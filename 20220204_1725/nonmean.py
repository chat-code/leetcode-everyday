#
# @lc app=leetcode id=1725 lang=python3
#
# [1725] Number Of Rectangles That Can Form The Largest Square
#

# @lc code=start
class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        cMax = 0
        c = 0

        for ii in rectangles:
            if min(ii) == cMax:
                c += 1

            elif min(ii) > cMax:
                c = 1
                cMax = min(ii)
        
        return c

        
# @lc code=end

