from collections import deque


class Solution:
    def integerReplacement_slow(self, n: int) -> int:
        q = deque()
        q.append((0, n))
        while q:
            i, cur = q.popleft()
            if cur == 1:
                return i
            if cur % 2 == 0:
                q.append((i + 1, cur // 2))
            else:
                q.append((i + 1, cur + 1))
                q.append((i + 1, cur - 1))

    def integerReplacement(self, n: int) -> int:
        cache = {1: 0}

        def dp(nn):
            if nn in cache:
                return cache[nn]
            elif nn % 2 == 0:
                cache[nn] = dp(nn // 2) + 1
            else:
                cache[nn] = min(dp(nn - 1) + 1, dp(nn + 1) + 1)
            return cache[nn]

        return dp(n)


if __name__ == "__main__":
    print(Solution().integerReplacement(7))
