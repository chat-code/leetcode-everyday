#
# @lc app=leetcode id=884 lang=python3
#
# [884] Uncommon Words from Two Sentences
#

# @lc code=start
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        r1 = set()
        r2 = set()

        w1 = s1.split()
        w2 = s2.split()

        for ii in w1:
            if ii in r1:
                r2.add(ii)
            else:
                r1.add(ii)

        for ii in w2:
            if ii in r2:
                r1.add(ii)
            else:
                r2.add(ii)
        
        r = list((r1 - r2))
        r.extend(list((r2 - r1)))
        
        return r

        
# @lc code=end

