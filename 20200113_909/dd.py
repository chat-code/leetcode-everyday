from typing import List


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        bb = list()
        flip = False
        for row in reversed(board):
            if flip:
                row.reverse()
            bb += row
            flip = not flip
        i = 1
        ls = {}
        for idx, b in enumerate(bb):
            if b != -1:
                bb[idx] -= 1
                ls[idx] = i
                i = i << 1
        i = i - 1
        heap = [(0, i)]
        dp = {0: 0}
        while heap:
            pos, mask = heap.pop(0)
            if pos + 6 >= len(bb) - 1:
                return dp[pos] + 1
            t = pos
            for npos in range(pos + 1, min(pos + 7, len(bb))):
                if bb[npos] == len(bb) - 1:
                    return dp[pos] + 1
                elif bb[npos] != -1 and mask & ls[npos]:
                    mask ^= ls[npos]
                    if bb[npos] not in dp:
                        dp[bb[npos]] = dp[pos] + 1
                        heap.append((bb[npos], mask))
                elif bb[npos] == -1:
                    t = max(npos, t)
            if t not in dp and t > pos and bb[t] == -1:
                dp[t] = dp[pos] + 1
                heap.append((t, mask))
        return -1


if __name__ == "__main__":
    # m = [[-1, -1, -1, -1, -1, -1],
    #      [-1, -1, -1, -1, -1, -1],
    #      [-1, -1, -1, -1, -1, -1],
    #      [-1, 35, -1, -1, 13, -1],
    #      [-1, -1, -1, -1, -1, -1],
    #      [-1, 15, -1, -1, -1, -1]]
    # m = [[-1, -1, -1], [-1, 9, 8], [-1, 8, 9]]
    m = [[-1, 5, -1, -1, 17, 6, -1], [41, 28, -1, -1, -1, 27, -1], [35, 42, -1, -1, -1, -1, 4],
         [7, 32, -1, 25, -1, 43, -1], [-1, 26, 5, -1, -1, -1, 25], [28, -1, -1, 5, -1, -1, 41],
         [-1, 42, 28, 25, -1, 7, 28]]

    print(Solution().snakesAndLadders(m))
