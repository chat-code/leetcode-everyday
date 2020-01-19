class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        s = 1
        ss = []
        for i in range(1, n + 1):
            ss.append(s)
            s *= i
        k = k - 1

        nums = [i for i in range(1, n + 1)]
        ans = []
        print(ss)
        for s in reversed(ss):
            v = k // s
            ans.append(str(nums.pop(v)))
            k = k % s
        return "".join(ans)


if __name__ == "__main__":
    print(Solution().getPermutation(4, 9))
    print(Solution().getPermutation_slow(4, 9))
