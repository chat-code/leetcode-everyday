from collections import Counter


class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        visited = Counter()
        word_count = Counter()
        left_idx = 0
        for idx, w in enumerate(s):
            visited.setdefault(w, 0)
            visited[w] += 1
            while len(visited) > maxLetters or idx + 1 - left_idx > minSize:
                visited[s[left_idx]] -= 1
                if visited[s[left_idx]] == 0:
                    del visited[s[left_idx]]
                left_idx += 1
            if idx + 2 - left_idx - minSize > 0:
                w = s[left_idx: idx + 1]
                word_count.setdefault(w, 0)
                word_count[w] += 1
        if not word_count:
            return 0
        return word_count.most_common(1)[0][1]


if __name__ == "__main__":
    # s = "aababcaab"
    # maxLetters = 2
    # minSize = 3
    # maxSize = 4
    # s = "aaaa"
    # maxLetters = 1
    # minSize = 3
    # maxSize = 3
    s = "abcde"
    maxLetters = 2
    minSize = 3
    maxSize = 3
    print(Solution().maxFreq(s, maxLetters, minSize, maxSize))

