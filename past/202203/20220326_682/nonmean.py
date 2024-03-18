#
# @lc app=leetcode id=682 lang=python3
#
# [682] Baseball Game
#

# @lc code=start
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        r = []

        for ii in ops:
            if ii == "C":
                r.pop()
            elif ii == "D":
                r.append(2 * r[-1])
            elif ii == "+":
                r.append(r[-1] + r[-2])
            else:
                r.append(int(ii))

        return sum(r)
        
        
# @lc code=end

