#
# @lc app=leetcode id=1189 lang=python3
#
# [1189] Maximum Number of Balloons
#

# @lc code=start
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        rDict = {}
        for ii in "balon":
            rDict[ii] = 0

        for ii in text:
            if ii in "balon":
                rDict[ii] += 1
        
        r = []
        for ii in "balon":
            if ii in "ban":
                r.append(rDict[ii])
            else:
                r.append(rDict[ii]/2)

        return int(min(r))

                
# @lc code=end

