from math import inf
from typing import List

direction = [(1, 0), (0, 1), (0, -1), (-1, 0), (0, 0)]


def matrix_copy(mat: List[List[int]]):
    m = []
    for row in mat: m.append(row.copy())
    return m


def flip(x):
    return 0 if x == 1 else 1


def op(mat: List[List[int]], x, y, h, w):
    for a, b in direction:
        nx = a + x
        ny = b + y
        if w > nx >= 0 and h > ny >= 0:
            mat[ny][nx] = flip(mat[ny][nx])


def is_zero(mat):
    for r in mat:
        for i in r:
            if i != 0:
                return False
    return True


class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        height = len(mat)
        width = len(mat[0])
        n = height * width
        mini = inf
        for code in range(2 ** n):
            matcp = matrix_copy(mat)
            count = 0
            for i in range(n):
                if 0X1 << i & code:
                    x = i % width
                    y = i // width
                    op(matcp, x, y, height, width)
                    count += 1
            if is_zero(matcp):
                mini = min(mini, count)
        return mini if mini != inf else -1

