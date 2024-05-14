class Solution:
    def countPalindromicSubsequences(self, S: str) -> int:
        count = 0
        length = len(S)
        prefix = [0] * length
        pprefix = prefix.copy()
        for start in reversed(range(length)):
            acc = 1
            for end in range(start, length):
                last_acc = acc
                if S[start] == S[end]:
                    # cur prefix plus one minux the last prefix with the same char
                    acc = prefix[end] + 1 - pprefix[end]
                    # memorize the current prefix
                    pprefix[end] = prefix[end] + 1
                # prefix should delay for an acc
                prefix[end] = (prefix[end] + last_acc) % 1000000007
            count = (count + acc) % 1000000007
        return count


if __name__ == "__main__":
    S = "baaddaaabaddccbbbdcbcccbdbdabdabdbadabddbbcbbcabbccdaccdbcbbcdcdbaadbcadacabcaaaadbcaddbbacddcdabaadcacacdcabaadacadcccdcbbcdabdcdacaacdcdbdacb"
    # S = 'adbckb'
    S = "aaba"
    print(Solution().countPalindromicSubsequences(S))
