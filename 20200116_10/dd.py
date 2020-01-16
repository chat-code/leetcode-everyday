from functools import lru_cache


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return match(s, p)


@lru_cache()
def match(s: str, p: str) -> bool:
    if not s and not p:
        return True
    elif len(p) > 1 and p[1] == "*":
        if s and (p[0] in {s[0], '.'}):
            if match(s[1:], p):
                return True
            elif match(s[1:], p[2:]):
                return True
        return match(s, p[2:])
    elif s and p and (p[0] in {s[0], '.'}):
        return match(s[1:], p[1:])
    return False


if __name__ == "__main__":
    s = "aa"
    p = "a*"
    print(s)
    print(p)
    print(Solution().isMatch(s, p))
