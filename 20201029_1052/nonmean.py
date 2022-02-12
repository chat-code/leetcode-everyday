#
# @lc app=leetcode id=1052 lang=python3
#
# [1052] Grumpy Bookstore Owner
#

# @lc code=start
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        if minutes >= len(customers):
            return sum(customers)

        n = 0
        c = 0
        d = 0
        s = 0
        cMax = 0

        for ii in range(0, len(customers)):
            n += 1

            if grumpy[ii] == 0:
                s += customers[ii]
                d += customers[ii]
            
            c += customers[ii]

            if n > minutes:
                c -= customers[ii - minutes]

                if grumpy[ii - minutes] == 0:
                    d -= customers[ii - minutes]

            cMax = max(cMax, c - d)

        return s + cMax  

        
# @lc code=end

