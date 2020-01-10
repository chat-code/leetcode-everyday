from typing import List

MOD = 10 ** 9 + 7


class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        dp = [[1 for _ in range(6)]]
        dps = [[1 for _ in range(6)]]

        for pos in range(1, n):
            lpos = pos - 1
            row = []
            srow = []
            for i in range(6):
                s = 0
                ss = 0
                for j in range(6):
                    s += dp[lpos][j] % MOD
                    if i == j:
                        if pos - rollMax[j] >= 0:
                            s -= dps[pos - rollMax[j]][j]
                    else:
                        ss += dp[lpos][j] % MOD
                srow.append(ss)
                row.append(s)
            dp.append(row)
            dps.append(srow)
        return sum(dp[-1]) % MOD


if __name__ == "__main__":
    # n = 2
    # rollMax = [1, 1, 2, 2, 2, 3]
    # n = 3
    # rollMax = [1, 1, 1, 2, 2, 3]
    # n = 2
    # rollMax = [1, 1, 1, 1, 1, 1]
    # n = 4
    # rollMax = [2, 1, 1, 3, 3, 2]

    n = 20
    rollMax = [8, 5, 10, 8, 7, 2]
    print(Solution().dieSimulator(n, rollMax))
