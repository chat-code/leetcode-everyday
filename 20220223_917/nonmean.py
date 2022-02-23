#
# @lc app=leetcode id=917 lang=python3
#
# [917] Reverse Only Letters
#

# @lc code=start
class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        k = ""
        ii = 0
        jj = len(s) - 1

        s = [ord(ii) for ii in s]

        while ii < len(s):
            if not ((s[ii] <= 90 and s[ii] >= 65) or (s[ii] <= 122 and s[ii] >= 97)):
                k += chr(s[ii])
                
            else:
                while not ((s[jj] <= 90 and s[jj] >= 65) or (s[jj] <= 122 and s[jj] >= 97)):
                    jj -= 1
                
                k += chr(s[jj])
                jj -= 1

            ii += 1
        
        return k
        
# @lc code=end

