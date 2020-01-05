# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
from dataclasses import dataclass


@dataclass
class NestedInteger:
    value: int = None

    def isInteger(self):
        """
        @return True if this NestedInteger holds a single integer, rather than a nested list.
        :rtype bool
        """

    def add(self, elem):
        """
        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
        :rtype void
        """

    def setInteger(self, value):
        """
        Set this NestedInteger to hold a single integer equal to value.
        :rtype void
        """

    def getInteger(self):
        """
        @return the single integer that this NestedInteger holds, if it holds a single integer
        Return None if this NestedInteger holds a nested list
        :rtype int
        """

    def getList(self):
        """
        @return the nested list that this NestedInteger holds, if it holds a nested list
        Return None if this NestedInteger holds a single integer
        :rtype List[NestedInteger]
        """


class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        stack = []
        acc = ''
        prev = ']'
        for i in s:
            if i == '[':
                acc = ''
                stack.append('[')
            elif i == ']':
                if prev != ']' and acc != '':
                    stack.append(NestedInteger(int(acc)))
                    acc = ''
                row = NestedInteger()
                rev_row = []
                while stack[-1] != '[':
                    rev_row.append(stack.pop())
                for x in reversed(rev_row):
                    row.add(x)
                stack.pop()
                stack.append(row)
            elif i == ',':
                if prev != ']':
                    stack.append(NestedInteger(int(acc)))
                    acc = ''
            else:
                acc += i
            prev = i
        if prev != ']':
            return NestedInteger(int(acc))
        return stack.pop()


if __name__ == "__main__":
    # s = "[123,[456,[789]]]"
    s = "[123]"
    print(Solution().deserialize(s))
