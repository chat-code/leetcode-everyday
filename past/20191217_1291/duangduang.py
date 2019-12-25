from typing import List


class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        low_len = len(str(low))
        high_len = len(str(high))
        res = []
        s = "123456789"
        for i in range(low_len, high_len + 1):
            for j in range(10 - i):
                cur = int(s[j:j + i])
                if low <= cur <= high:
                    res.append(cur)
        return res


if __name__ == "__main__":
    low = 1000
    high = 13000
    print(Solution().sequentialDigits(low, high))
