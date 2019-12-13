from typing import List


class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        if cheeseSlices * 2 > tomatoSlices or cheeseSlices * 4 < tomatoSlices:
            return []
        if tomatoSlices % 2 == 1:
            return []

        total_jumbo = (tomatoSlices - cheeseSlices * 2) // 2
        total_small = cheeseSlices - total_jumbo
        return [total_jumbo, total_small]

