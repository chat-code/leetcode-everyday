#
# @lc app=leetcode id=224 lang=python3
#
# [224] Basic Calculator
#

# @lc code=start
class Solution:
    def calculate(self, s: str) -> int:
        c = []
        b = []
        e = []
        d = tuple(str(ii) for ii in range(0, 10))

        if s[0] == "+" or s[0] == "-":
            s = "0" + s
        
        ii = 0
        while ii <= len(s) - 1:
            if s[ii] == "(":
                b.append(s[ii])
                e.append(s[ii])
                c.append(s[ii])
                ii += 1

                if s[ii] == "+" or s[ii] == "-":
                    c.append(0)

            elif s[ii] == ")":
                e.pop()

                p = []

                while True:
                    p.append(c.pop())

                    if p[-1] == "(":
                        p.pop()
                        break
                q = []

                while True:
                    q.append(b.pop())

                    if q[-1] == "(":
                        q.pop()
                        break
                
                while len(q) > 0:
                    n2 = int(p.pop())
                    n1 = int(p.pop())

                    m = q.pop()
                    
                    if m == "+":
                        n = n1 + n2
                    else:
                        n = n2 - n1
                    p.append(n)
                
                c.extend(p)
                
                ii += 1
            
            elif s[ii] == " ":
                ii += 1

            elif s[ii] == "+" or s[ii] == "-":
                b.append(s[ii])
                ii += 1
            else:
                p = s[ii]
                if not (ii < len(s) - 1 and s[ii+1] in d):
                    ...
                else:
                    while (ii < len(s) - 1 and s[ii+1] in d):
                        ii += 1
                        p += s[ii]

                ii += 1

                c.append(int(p))

        
        b = b[::-1]
        c = c[::-1]

        while len(b) > 0:
            n2 = int(c.pop())
            n1 = int(c.pop())

            m = b.pop()
            if m == "+":
                n = n1 + n2
            else:
                n = n2 - n1
            c.append(n)
        
        return c[-1]

        
# @lc code=end

