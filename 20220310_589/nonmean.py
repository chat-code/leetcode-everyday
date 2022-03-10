#
# @lc app=leetcode id=589 lang=python3
#
# [589] N-ary Tree Preorder Traversal
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

from functools import lru_cache


class Solution:
    @lru_cache(None)
    def preorder(self, root: 'Node') -> List[int]:
        if root is None:
            return []

        res = [root.val]

        for ii in root.children:
            if ii is not None:
                res.extend(self.preorder(ii))

        return res

        
# @lc code=end

