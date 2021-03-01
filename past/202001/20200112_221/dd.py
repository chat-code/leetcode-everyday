from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if len(matrix) < 1:
            return 0
        height, width = len(matrix), len(matrix[0])
        mini = min(height, width)
        ans = 0
        colsum = [0] * width
        for i in range(height):
            length = ans + 1
            prev_ans = ans
            count = 0
            for j in range(width):
                colsum[j] += (0 if matrix[i][j] == '0' else 1)
                if ans < length:
                    if colsum[j] != length:
                        if count >= length:
                            ans = length
                        count = 0
                    else:
                        count += 1
            if count >= length:
                ans = length
            if ans >= mini:
                break
            if prev_ans == ans:
                for j in range(width):
                    colsum[j] -= (0 if matrix[i - prev_ans][j] == '0' else 1)
        return ans * ans


if __name__ == "__main__":
    # m = [["1", "0", "1", "0", "0"], ["1", "0", "1", "1", "1"], ["1", "1", "1", "1", "1"], ["1", "0", "0", "1", "0"]]
    m = [["0", "0", "0"], ["0", "0", "0"], ["1", "1", "1"]]
    print(Solution().maximalSquare(m))
