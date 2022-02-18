#
# @lc app=leetcode id=743 lang=python3
#
# [743] Network Delay Time
#

# @lc code=start
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        
        def findPath(rDict, v, ks):
            new_k = []

            if len(ks) == 0:
                return new_k

            while len(ks) > 0:
                k = ks.pop()

                if v[k[1] - 1] is None or v[k[1] - 1] > v[k[0] - 1] + k[2]: 
                    v[k[1] - 1] = v[k[0] - 1] + k[2] 

                    new_k.extend(rDict.get(k[1], []))

            findPath(rDict, v, new_k)

        rDict = {}

        for ii in times:
            if ii[0] in rDict.keys():
                rDict[ii[0]].append(ii)
            else:
                rDict[ii[0]] = [ii]
        
        v = [None] * n        
        v[k-1] = 0

        findPath(rDict, v, rDict.get(k, []))

        return -1 if None in v else max(v)

        
# @lc code=end

