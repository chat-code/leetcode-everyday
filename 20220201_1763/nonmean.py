#
# @lc app=leetcode id=1763 lang=python3
#
# [1763] Longest Nice Substring
#

# @lc code=start
class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        def search_str(s, res):
            u = [0] * 26
            l = [0] * 26

            for ii in s:
                c = ord(ii)

                if c > 90:
                    u[c - 97] = 1
                else:
                    l[c - 65] = 1
            
            for ii in range(0, len(u)):
                if u[ii] == 1 and l[ii] == 0:
                    s = s.replace(chr(ii+97), ",")
                elif u[ii] == 0 and l[ii] == 1:
                    s = s.replace(chr(ii+65), ",")
            
            p = s.split(",")

            if len(p) == 1:
                res.append(p[0])
            else:
                for ii in p:
                    search_str(ii, res)

        res = []        
        s = search_str(s, res)

        p = ""
        for ii in res:
            if len(ii) > len(p):
                p = ii

        return p
        
        
# @lc code=end

