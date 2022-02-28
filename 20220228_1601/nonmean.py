#
# @lc app=leetcode id=1601 lang=python3
#
# [1601] Maximum Number of Achievable Transfer Requests
#

# @lc code=start
class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        
        def answerRequest(requests, c, ii, r):
            if ii == len(requests):
                if sum([abs(ii) for ii in r]) == 0:
                    return c
                else:
                    return 0

            res1 = answerRequest(requests, c, ii+1, r)
            
            r[requests[ii][0]] -= 1
            r[requests[ii][1]] += 1

            res2 = answerRequest(requests, c+1, ii+1, r) 

            r[requests[ii][1]] -= 1
            r[requests[ii][0]] += 1

            return max(res1, res2)

        res = answerRequest(requests, 0, 0, [0]*n)

        return res        
            
        
# @lc code=end

