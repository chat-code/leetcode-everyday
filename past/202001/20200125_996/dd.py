from math import isqrt
from typing import List


class Solution:
    def numSquarefulPerms(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0

        def dfs(ns, last=None):
            nonlocal ans
            ss = set()
            if not ns:
                ans += 1
            for i in range(len(ns)):
                if ns[i] in ss:
                    continue
                ss.add(ns[i])
                if last is not None and not isqrt(last + ns[i]) ** 2 == last + ns[i]:
                    continue
                dfs(ns[0:i] + ns[i + 1:n], ns[i])

        dfs(nums)
        return ans


if __name__ == "__main__":
    nums = [1, 17, 8]
    print(Solution().numSquarefulPerms(nums))
