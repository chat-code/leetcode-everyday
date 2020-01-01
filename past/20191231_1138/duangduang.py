class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        bottom = ord('a')
        xp = yp = 0
        s = ""
        for i in target:
            n = ord(i) - bottom
            x, y = n % 5, n // 5
            xo, yo = x - xp, y - yp
            if yo < 0: s += "U" * (-yo)
            if xo < 0: s += "L" * (-xo)
            if xo > 0: s += "R" * xo
            if yo > 0: s += "D" * yo
            s += "!"
            xp, yp = x, y
        return s


if __name__ == "__main__":
    target = "leet"
    print(Solution().alphabetBoardPath(target))

