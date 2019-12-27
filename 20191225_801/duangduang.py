import functools
from math import inf
from typing import List


class Solution:
    def minSwap_slow(self, A: List[int], B: List[int]) -> int:
        length = len(A)

        @functools.lru_cache()
        def minSwapEev(x, y, k):
            if k < length:
                xm0 = max(A[k], x)
                ym0 = max(B[k], y)
                xm1 = max(B[k], x)
                ym1 = max(A[k], y)
                if A[k] > x and B[k] > y and B[k] > x and A[k] > y:
                    r0 = minSwapEev(xm0, ym0, k + 1)
                    r1 = minSwapEev(xm1, ym1, k + 1)
                    return r1 + 1 if r1 + 1 < r0 else r0
                elif A[k] > x and B[k] > y:
                    return minSwapEev(xm0, ym0, k + 1)
                elif B[k] > x and A[k] > y:
                    return minSwapEev(xm1, ym1, k + 1) + 1
            else:
                return 0

        return minSwapEev(-inf, -inf, 0)

    def minSwap(self, A: List[int], B: List[int]) -> int:
        n = 0
        s = 1
        for i in range(1, len(A)):
            if A[i] <= B[i - 1] or B[i] <= A[i - 1]:
                s += 1
            elif A[i] <= A[i - 1] or B[i] <= B[i - 1]:
                s, n = n + 1, s
            else:
                s, n = min(s, n) + 1, min(s, n)
        return min(s, n)


if __name__ == "__main__":
    A = [1, 3, 5, 4]
    B = [1, 2, 3, 7]
    print(Solution().minSwap(A, B))

