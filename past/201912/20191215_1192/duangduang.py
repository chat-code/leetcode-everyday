from time import time
from math import inf
from typing import List


class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        parent = [None] * n
        low = [inf] * n
        order = [inf] * n
        visited = [False] * n
        graph: List = [[] for i in range(n)]
        result = []
        count = 0
        for a, b in connections:
            graph[a].append(b)
            graph[b].append(a)

        def dfs_targan(u):
            nonlocal count
            visited[u] = True
            low[u] = order[u] = count
            count += 1
            for v in graph[u]:
                if not visited[v]:
                    parent[v] = u
                    # update v' low status to final status
                    dfs_targan(v)
                    # if v is not connected to parent of u
                    if low[v] > order[u]:
                        result.append([u, v])
                if v != parent[u]:
                    # update u to the lowest
                    low[u] = min(low[u], low[v])

        dfs_targan(0)
        return result

    def criticalConnections_slow(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        def dfs_cycles(u, p, color: List[int], parent: List[int]):
            if color[u[1]] == 2:
                return
            elif color[u[1]] == 1:
                current = p
                res.discard(u[0])
                while current[1] != u[1]:
                    last = current
                    current = parent[current[1]]
                    res.discard(last[0])
            else:
                parent[u[1]] = p
                color[u[1]] = 1
                for v in graph[u[1]]:
                    if v[1] != parent[u[1]][1]:
                        dfs_cycles(v, u, color, parent)
                color[u[1]] = 2

        graph = [[] for _ in range(n)]
        res = set()
        for idx, k in enumerate(connections):
            a, b = k
            graph[a].append((idx, b))
            graph[b].append((idx, a))
            res.add(idx)
        colors = [0] * n
        parents = [0] * n
        first = connections[0]
        # get the one with connection to the rest
        child = first[0] if len(graph[first[0]]) > 1 else first[1]
        par = first[1] if len(graph[first[0]]) > 1 else first[0]
        dfs_cycles((child, 0), (par, 0), colors, parents)
        result = []
        for i in res:
            result.append(connections[i])
        return result


if __name__ == "__main__":
    # n = 4
    # connections = [[0, 1], [1, 2], [2, 0], [1, 3]]
    n = 5
    connections = [[1, 0], [2, 0], [3, 2], [4, 2], [4, 3], [3, 0], [4, 0]]
    t = time()
    print(Solution().criticalConnections(n, connections))
    print(Solution().criticalConnections_slow(n, connections))
    te = time()
    print(te - t)

