#
# @lc app=leetcode id=537 lang=python3
#
# [537] Complex Number Multiplication
#

# @lc code=start
class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        # (a1 + b1*i) * (a2 + b2*i)
        # = (a1 * a2 - b1 * b2) + (a1 * b2 + b1 * a2) * i

        n1 = [int(ii) for ii in num1[:-1].split("+")]
        n2 = [int(ii) for ii in num2[:-1].split("+")]

        return "%d+%di" %((n1[0] * n2[0] - n1[1] * n2[1]), (n1[0] * n2[1] + n1[1] * n2[0]))


# @lc code=end

