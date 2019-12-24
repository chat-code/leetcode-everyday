from typing import List


class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        nums.sort()
        last = None
        cur_idx = 0
        base_idx = 0
        lst = []
        for cur in nums:
            if cur == last:
                cur_idx += 1
            else:
                cur_idx = base_idx
            if len(lst) <= cur_idx:
                lst.append([1, cur])
            elif lst[cur_idx][1] + 1 == cur:
                if lst[cur_idx][0] + 1 == k:
                    base_idx = cur_idx + 1
                lst[cur_idx][0] += 1
                lst[cur_idx][1] = cur
            else:
                return False
            last = cur
        return len(lst) == base_idx


if __name__ == "__main__":
    nums = [3, 2, 1, 2, 3, 4, 3, 4, 5, 9, 10, 11]
    k = 3
    # nums = [1, 2, 3, 3, 4, 4, 5, 6]
    # k = 4
    # nums = [15, 16, 17, 18, 19, 16, 17, 18, 19, 20, 6, 7, 8, 9, 10, 3, 4, 5, 6, 20]
    # k = 5
    print(Solution().isPossibleDivide(nums, k))

