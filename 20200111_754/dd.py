class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        count = i = 0
        while True:
            i += 1
            count += i
            if count >= target and (count + target) % 2 == 0:
                return i


if __name__ == "__main__":
    # print(Solution().reachNumber(5000))
    print(Solution().reachNumber(-1000000000))
