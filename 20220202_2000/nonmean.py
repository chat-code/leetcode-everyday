#
# @lc app=leetcode id=2000 lang=python3
#
# [2000] Reverse Prefix of Word
#

# @lc code=start
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        ii = 0
        s = ""
        flag = False

        while ii < len(word):
            s += word[ii]
            ii += 1
            
            if s[-1] == ch and not flag:
                s = s[::-1]
                flag = True

        return s

        
# @lc code=end

