from typing import List


class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if not timeSeries:
            return 0
        ans = 0
        last_t = timeSeries[0]
        for t in timeSeries[1:]:
            ans += min(t - last_t, duration)
            last_t = t
        ans += duration
        return ans

