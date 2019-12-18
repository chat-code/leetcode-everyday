from typing import List


class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        right = 0
        count = 0
        for interval in intervals:
            if right < interval[1]:
                right = interval[1]
                count += 1
        return count


if __name__ == "__main__":
    intervals = [[1, 4], [3, 6], [2, 8]]
    print(Solution().removeCoveredIntervals(intervals))

