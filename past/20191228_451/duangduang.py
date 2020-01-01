from collections import Counter


class Solution:
    def frequencySort(self, s: str) -> str:
        counter = Counter(s)
        return "".join([i[0] * i[1] for i in counter.most_common()])

