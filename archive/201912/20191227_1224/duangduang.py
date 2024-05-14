from collections import Counter
from typing import List


class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        counter = Counter()
        left = 0
        right = 0
        freq = [0] * (len(nums) + 1)
        r = 0
        for idx, n in enumerate(nums):
            if n not in counter: left = 1
            counter.setdefault(n, 0)
            freq[counter[n]] -= 1
            counter[n] += 1
            right = max(counter[n], right)
            freq[counter[n]] += 1
            while freq[left] <= 0: left += 1
            if (left > 0 and right > 0 and freq[left] + freq[right] == len(counter) and (
                    (left == 1 and freq[left] == 1) or (right == left + 1 and freq[right] == 1))) \
                    or len(counter) == 1 \
                    or left == 1 and freq[left] == len(counter):
                r = idx
        return r + 1


if __name__ == "__main__":
    # nums = [2, 2, 1, 1, 5, 3, 3, 5]
    # nums = [1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5]
    # nums = [10, 2, 8, 9, 3, 8, 1, 5, 2, 3, 7, 6]
    nums = [1, 1]
    # nums = [1, 2]
    print(Solution().maxEqualFreq(nums))
