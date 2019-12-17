from pprint import pprint
from typing import List


class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        height = len(mat)
        width = len(mat[0])
        for i in range(height):
            for j in range(1, width):
                mat[i][j] += mat[i][j - 1]

        for i in range(1, height):
            for j in range(width):
                mat[i][j] += mat[i - 1][j]

        res, h, low = 0, min(height, width), 0
        while True:
            length = (h + low + 1) // 2
            if h == length or low == length:
                return res
            for x_off in range(height - length):
                for y_off in range(width - length):
                    right = length + y_off
                    down = length + x_off
                    if x_off == 0 == y_off:
                        sumi = mat[down][right]
                    elif x_off == 0:
                        sumi = mat[down][right] - mat[down][y_off - 1]
                    elif y_off == 0:
                        sumi = mat[down][right] - mat[x_off - 1][right]
                    else:
                        sumi = mat[down][right] + mat[x_off - 1][y_off - 1] - mat[x_off - 1][right] - mat[down][
                            y_off - 1]
                    if sumi <= threshold:
                        res = length + 1
            if res == length + 1:
                h, low = (h, length)
            else:
                h, low = (length, low)


if __name__ == "__main__":
    mat = [[1, 1, 3, 2, 4, 3, 2], [1, 1, 3, 2, 4, 3, 2], [1, 1, 3, 2, 4, 3, 2]]
    threshold = 4
    # mat = [[2, 2, 2, 2, 2], [2, 2, 2, 2, 2], [2, 2, 2, 2, 2], [2, 2, 2, 2, 2], [2, 2, 2, 2, 2]]
    # threshold = 1
    # mat = [[1, 1, 1, 1], [1, 0, 0, 0], [1, 0, 0, 0], [1, 0, 0, 0]]
    # threshold = 6
    print(Solution().maxSideLength(mat, threshold))

