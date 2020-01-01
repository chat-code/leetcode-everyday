class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        visited = set()
        maxi = left = right = 0
        for c in s:
            if c in visited:
                maxi = max(right - left, maxi)
                while c in visited:
                    visited.remove(s[left])
                    left += 1
            right += 1
            visited.add(c)
        maxi = max(right - left, maxi)
        return maxi


if __name__ == "__main__":
    # txt = "pwwkew"
    txt = " "
    txt = ""
    print(Solution().lengthOfLongestSubstring(txt))

