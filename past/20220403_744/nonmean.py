#
# @lc app=leetcode id=744 lang=python3
#
# [744] Find Smallest Letter Greater Than Target
#

# @lc code=start
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:

        return self.method1(letters, target)

    def method1(self, letters, target):
        for ii in letters:
            if ii > target:
                return ii
        
        return letters[0]

        
# @lc code=end

