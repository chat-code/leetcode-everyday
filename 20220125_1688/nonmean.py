#
# @lc app=leetcode id=1688 lang=python3
#
# [1688] Count of Matches in Tournament
#

# @lc code=start
class Solution:
    def numberOfMatches(self, n: int) -> int:
        c = 0
        while n > 1:
            k = n % 2
            n = (n - k) / 2 + k
            c += (n - k)

        return int(c)

        
# @lc code=end

