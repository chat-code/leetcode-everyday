from collections import deque


class Solution:
    def integerReplacement(self, n: int) -> int:
        q = deque()
        q.append((0, n))
        while q:
            print(q)
            i, cur = q.popleft()
            if cur == 1:
                return i
            if cur % 2 == 0:
                q.append((i + 1, cur // 2))
            else:
                q.append((i + 1, cur - 1))
                q.append((i + 1, cur + 1))


if __name__ == "__main__":
    print(Solution().integerReplacement(7))

