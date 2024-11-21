class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort()
        n = len(arr)
        prefix = [0]

        for nums in arr:
            prefix.append(prefix[-1] + nums)
        
        r, ans, diff = max(arr), 0, target
        for i in range(1, r+1):
            it = bisect.bisect_left(arr, i)
            cur = prefix[it] + (n - it) * i
            if abs(cur - target) < diff:
                ans, diff = i, abs(cur - target)
        
        return ans