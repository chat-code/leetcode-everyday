class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        count = 0
        dps = []
        t = 1
        for idx, i in enumerate(S):
            if i == '(':
                # addon
                if idx > 0 and S[idx - 1] == ')':
                    dps.append((count, t))
                count += 1
            else:
                count -= 1
                if S[idx - 1] == '(':
                    t = 1
                else:
                    t *= 2
                if dps and dps[-1][0] == count:
                    t += dps.pop()[1]
            # print(S[:idx+1], "--",S[idx+1:], t, i, S[idx-1], len(stack))
        return t


if __name__ == "__main__":
    s = "(()(()))"
    # s = "()(())"
    # s = "()"
    # s = "(())()"
    print(Solution().scoreOfParentheses(s))
