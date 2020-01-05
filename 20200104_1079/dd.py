from itertools import permutations


class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        return sum(len(set(permutations(tiles, r=i))) for i in range(1, 1 + len(tiles)))


if __name__ == "__main__":
    t = "AAB"
    t = "AAABBC"
    print(Solution().numTilePossibilities(t))
