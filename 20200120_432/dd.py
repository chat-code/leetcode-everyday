import heapq


class AllOne:

    def __init__(self):
        self.maxiq = []
        self.miniq = []
        self.dct = {}
        """
        Initialize your data structure here.
        """

    def inc(self, key: str) -> None:
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        """
        self.dct.setdefault(key, 0)
        self.dct[key] += 1
        heapq.heappush(self.maxiq, (-self.dct[key], key))
        heapq.heappush(self.miniq, (self.dct[key], key))

    def dec(self, key: str) -> None:
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        """
        if key in self.dct:
            self.dct[key] -= 1
            if not self.dct[key]:
                del self.dct[key]
            else:
                heapq.heappush(self.maxiq, (-self.dct[key], key))
                heapq.heappush(self.miniq, (self.dct[key], key))

    def getMaxKey(self) -> str:
        """
        Returns one of the keys with maximal value.
        """

        while self.maxiq:
            if self.maxiq[0][1] in self.dct and -self.maxiq[0][0] == self.dct[self.maxiq[0][1]]:
                return self.maxiq[0][1]
            heapq.heappop(self.maxiq)
        return ""

    def getMinKey(self) -> str:
        """
        Returns one of the keys with Minimal value.
        """
        while self.miniq:
            if self.miniq[0][1] in self.dct and self.miniq[0][0] == self.dct[self.miniq[0][1]]:
                return self.miniq[0][1]
            heapq.heappop(self.miniq)
        return ""
