from math import sqrt, floor


class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        upper = floor(sqrt(c))
        down = 0
        for i in range(upper, -1, -1):
            cur = i ** 2
            remain = c - cur
            if cur < remain: break
            while down ** 2 < remain: down += 1
            if down ** 2 == remain: return True
        return False


if __name__ == "__main__":
    # print(Solution().judgeSquareSum(0))
    print(Solution().judgeSquareSum(10))
    # print(Solution().judgeSquareSum(11))
    print(Solution().judgeSquareSum(4))
