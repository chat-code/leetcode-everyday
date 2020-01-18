class Solution:
    def convertToBase7(self, num: int) -> str:
        flag = "" if num >= 0 else "-"
        s = ""
        num = abs(num)
        while num != 0:
            s = str(num % 7) + s
            num //= 7
        if not s: return "0"
        return flag + s


if __name__ == "__main__":
    print(Solution().convertToBase7(0))
    # print(Solution().convertToBase7(-7))
