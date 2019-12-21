from typing import List


class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight

    def __repr__(self):
        return f"val: {self.val}"


class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def leaf(val):
            return Node(val, True, None, None, None, None)

        def node(val, tl, tr, bl, br):
            return Node(val, False, tl, tr, bl, br)

        def cons(x0, y0, x1, y1) -> 'Node':
            if x1 - x0 == 2:
                layer = [leaf(grid[y0][x0]),
                         leaf(grid[y0][x0 + 1]),
                         leaf(grid[y0 + 1][x0]),
                         leaf(grid[y0 + 1][x0 + 1])]
            else:
                xm = (x0 + x1) // 2
                ym = (y0 + y1) // 2
                layer = [cons(x0, y0, xm, ym),
                         cons(xm, y0, x1, ym),
                         cons(x0, ym, xm, y1),
                         cons(xm, ym, x1, y1)]

            value = layer[0].val
            for e in layer:
                if not e.isLeaf or e.val != value:
                    return node(None, *layer)
            return leaf(value)

        return cons(0, 0, len(grid[0]), len(grid))


if __name__ == "__main__":
    m = [[1, 1, 1, 1, 0, 0, 0, 0],
         [1, 1, 1, 1, 0, 0, 0, 0],
         [1, 1, 1, 1, 1, 1, 1, 1],
         [1, 1, 1, 1, 1, 1, 1, 1],
         [1, 1, 1, 1, 0, 0, 0, 0],
         [1, 1, 1, 1, 0, 0, 0, 0],
         [1, 1, 1, 1, 0, 0, 0, 0],
         [1, 1, 1, 1, 0, 0, 0, 0]]
    tree = Solution().construct(m)
    print(tree.topLeft)
    print(tree.topRight)
    print(tree.bottomLeft)
    print(tree.bottomRight)

