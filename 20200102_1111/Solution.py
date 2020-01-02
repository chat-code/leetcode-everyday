from typing import List


class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        left_count = 0
        right_count = 0
        ans = []
        for i in seq:
            if i == "(":
                if left_count < right_count:
                    ans.append(0)
                    left_count += 1
                else:
                    ans.append(1)
                    right_count += 1
            else:
                if left_count < right_count:
                    ans.append(1)
                    right_count -= 1
                else:
                    ans.append(0)
                    left_count -= 1
        return ans
