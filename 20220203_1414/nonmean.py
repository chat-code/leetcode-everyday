#
# @lc app=leetcode id=1414 lang=python3
#
# [1414] Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
#

# @lc code=start
class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        f = [1, 1]
        while f[-1] < k:
            n = f[-1] + f[-2]
            if n == k:
                return 1

            f.append(n)

        f.pop()
        
        ii = len(f) - 1

        c = 0
        while ii >= 0:
            if k == f[ii]:
                return c + 1

            while k > f[ii]:
                k -= f[ii]
                c += 1

            ii -= 1
        
        return c

        
# @lc code=end

