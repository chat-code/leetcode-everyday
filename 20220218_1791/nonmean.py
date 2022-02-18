#
# @lc app=leetcode id=1791 lang=python3
#
# [1791] Find Center of Star Graph
#

# @lc code=start
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:

        rDict = {}
        for ii in edges:
            rDict[ii[0]] = rDict.get(ii[0], 0) + 1
            rDict[ii[1]] = rDict.get(ii[1], 0) + 1

        m = -1
        n = -1

        for ii in rDict.keys():
            if rDict[ii] > n:
                n = rDict[ii]
                m = ii
        
        return m

        
# @lc code=end

