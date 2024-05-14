from typing import List


class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        return sum(0 if i == j else 1 for i, j in zip(heights, sorted(heights)))


if __name__ == "__main__":
    heights = [1, 1, 4, 2, 1, 3]  # s = "()(())"
    print(Solution().heightChecker(heights))
