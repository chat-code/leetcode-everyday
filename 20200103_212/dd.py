from dataclasses import dataclass
from typing import List, Dict, Set, Optional


@dataclass
class Node:
    char: str
    children: Dict[str, 'Node']
    parent: Optional['Node']
    is_word = False
    word = None

    def get_word(self):
        if not self.word:
            w = ""
            p = self
            while p.parent:
                w = p.char + w
                p = p.parent
            self.word = w
        return self.word


def build_trie(words: List[str]) -> 'Node':
    root: Node = Node('\0', dict(), None)
    for word in words:
        cur: Node = root
        for c in word:
            if c not in cur.children:
                cur.children[c] = Node(c, dict(), cur)
            cur = cur.children[c]
        cur.is_word = True
    return root


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = build_trie(words)
        h = len(board)
        w = len(board[0])
        ans = set()
        visited = set()

        def next_locations(xi, yi):
            for a, b in [(1, 0), (0, 1), (0, -1), (-1, 0)]:
                nx = a + xi
                ny = b + yi
                if w > nx >= 0 and h > ny >= 0:
                    yield nx, ny

        def search_one(node: Node, x, y):
            if board[y][x] in node.children and (x, y) not in visited:
                visited.add((x, y))
                node = node.children[board[y][x]]
                if node.is_word:
                    ans.add(node.get_word())
                for xi, yi in next_locations(x, y):
                    search_one(node, xi, yi)
                visited.remove((x, y))

        for i in range(w):
            for j in range(h):
                search_one(root, i, j)
        return list(ans)


if __name__ == "__main__":
    board = [
        ['o', 'a', 'a', 'n'],
        ['e', 't', 'a', 'e'],
        ['i', 'h', 'k', 'r'],
        ['i', 'f', 'l', 'v']
    ]
    words = ["oath", "pea", "eat", "rain"]
    print(Solution().findWords(board, words))

