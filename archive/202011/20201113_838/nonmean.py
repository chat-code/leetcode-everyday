#
# @lc app=leetcode id=838 lang=python3
#
# [838] Push Dominoes
#

# @lc code=start
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        ii = 0
        jj = 0
        s = ""

        while ii < len(dominoes):
            if dominoes[jj] != ".":
                if ii != jj:
                    if dominoes[ii] != "R" and dominoes[jj] == "R":
                        s += dominoes[ii:jj]

                    elif dominoes[ii] == "R" and dominoes[jj] == "L":
                        k = jj - ii - 1

                        if k % 2 == 1:
                            s += ("R" * (k // 2 + 1) + "." + "L" * (k // 2))
                        else:
                            s += ("R" * (k // 2 + 1) + "L" * (k // 2))

                    else:
                        s += dominoes[jj] * (jj - ii)

                ii = jj
            
            if jj < len(dominoes) - 1:
                jj += 1
            else:
                if dominoes[jj] != ".":
                    s += dominoes[jj]
                else:
                    if dominoes[ii] == "R":
                        s += "R" * (jj - ii + 1)
                    else:
                        s += dominoes[ii:]

                return s

        
# @lc code=end

