from typing import List


class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        counter = {}
        eles = set()
        for i in A:
            if i not in eles:
                eles.add(i)
            else:
                counter.setdefault(i, 0)
                counter[i] += 1

        r = 0
        count = 0
        for c in sorted(counter):
            count = max(c, count)
            for _ in range(counter[c]):
                while count in eles:
                    count += 1
                r += count - c
                eles.add(count)
        return r


if __name__ == "__main__":
    a = [1, 2, 2]
    a = [0, 2, 2]
    print(Solution().minIncrementForUnique(a))
