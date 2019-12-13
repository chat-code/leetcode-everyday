from typing import List


class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        h = len(matrix)
        w = len(matrix[0])
        acc = 0
        dp = [0] * len(matrix[0])
        pre_dp = [0] * len(matrix[0])
        for hx in range(0, h):
            for wx in range(0, w):
                if not matrix[hx][wx]:
                    dp[wx] = 0
                elif wx == 0 or hx == 0:
                    dp[wx] = matrix[hx][wx]
                else:
                    dp[wx] = min(dp[wx - 1], pre_dp[wx], pre_dp[wx - 1]) + 1
                acc += dp[wx]
            pre_dp, dp = dp, pre_dp
        return acc


if __name__ == "__main__":
    matrix = [
        [0, 1, 1, 1],
        [1, 1, 1, 1],
        [0, 1, 1, 1]
    ]
    # matrix = [
    #     [1, 0, 1],
    #     [1, 1, 0],
    #     [1, 1, 0]
    # ]
    print(Solution().countSquares(matrix))

