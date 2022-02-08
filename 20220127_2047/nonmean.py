#
# @lc app=leetcode id=2047 lang=python3
#
# [2047] Number of Valid Words in a Sentence
#

# @lc code=start
class Solution:
    def countValidWords(self, sentence: str) -> int:
        words = sentence.split()

        p = ["!", ".", ","]
        d = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
        
        c = 0
        for w in words:
            n = 0
            k = -1
            
            flag = True
            for ii in range(0, len(w)):
                if w[ii] in d:
                    flag = False
                    break

                elif w[ii] == "-":
                    if k >= 0:
                        flag = False
                        break
                    else:
                        k = ii

                elif w[ii] in p:
                    if n == 1:
                        flag = False
                        break
                    else:
                        n += 1

            if flag:
                if n == 1 and w[-1] not in p:
                    continue

                if k >= 0:
                    if (w[0] == "-" or w[-1] == "-"):
                        continue
                    else:
                        if w[k-1] in d or w[k+1] in p or w[k-1] in d or w[k+1] in p:
                            continue
            
                c += 1

        return c

        
# @lc code=end

