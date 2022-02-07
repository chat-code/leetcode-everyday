#
# @lc app=leetcode id=1405 lang=python3
#
# [1405] Longest Happy String
#

# @lc code=start
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        n = [a, b, c]        
        m = ["a", "b", "c"]
        l = [0, 0, 0]

        def popChar(n, m, l):
            for ii in range(0, 3):
                jj = (ii + 1) % 3
                kk = (ii + 2) % 3

                if n[ii] >= n[jj] and n[ii] >= n[kk] and n[ii] > 0 and l[ii] < 2                                     \
                    or n[ii] <= n[jj] and n[ii] >= n[kk] and n[ii] > 0 and l[ii] < 2 and l[jj] == 2                  \
                    or n[ii] <= n[kk] and n[ii] >= n[jj] and n[ii] > 0 and l[ii] < 2 and l[kk] == 2                  \
                    or n[ii] <= n[jj] and n[ii] <= n[kk] and n[ii] > 0 and l[ii] < 2 and l[jj] == 2 and l[kk] == 2:  \

                    l[ii] += 1
                    n[ii] -= 1

                    l[jj] = 0
                    l[kk] = 0

                    return m[ii]

            return None
        
        s = ""
        for _ in range(0, a + b + c + 1):
            p = popChar(n, m, l)

            if p is not None:
                s += p
            else:
                return s
            
# @lc code=end

