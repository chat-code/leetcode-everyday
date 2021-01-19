from typing import List


class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        ans = []
        for q in queries:
            pattern_count = 0
            for s in q:
                if s.isupper():
                    if pattern_count >= len(pattern) or s != pattern[pattern_count]:
                        pattern_count = -1
                        break
                    else:
                        pattern_count += 1
                else:
                    if pattern_count < len(pattern) and s == pattern[pattern_count]:
                        pattern_count += 1
            ans.append(pattern_count == len(pattern))
        return ans


if __name__ == "__main__":
    # queries = ["FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"]
    # pattern = "FB"
    queries = ["FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"]
    pattern = "FoBa"
    print(Solution().camelMatch(queries, pattern))
