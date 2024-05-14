
from typing import List


class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        cur = left = 0
        right = len(nums) - 1
        visited = set()
        cur_visited = set()

        def step(x):
            r = (nums[x] + x) % len(nums)
            return r

        def check_single(start):
            flag = nums[start] > 0
            curr = step(start)
            if curr == start:
                return False
            while curr != start:
                if not flag == (nums[curr] > 0): return False
                curr = step(curr)
            return True

        while left <= right:
            cur_visited.add(cur)
            cur = step(cur)
            if cur in cur_visited:
                visited.update(cur_visited)
                cur_visited = set()
                if check_single(cur):
                    return True
                else:
                    while left in visited: left += 1
                    while right in visited: right -= 1
                    cur = left
        return False


if __name__ == "__main__":
    k = [-2, 1, -1, -2, -2]
    k = [-1, 2]
    print(Solution().circularArrayLoop(k))
