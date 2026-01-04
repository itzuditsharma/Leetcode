class Solution:
    def dfs(self, node, col, color, graph):
        color[node] = col

        for it in graph[node]:
            if color[it] == -1:
                if self.dfs(it, not col, color, graph) == False:
                    return False
            elif color[it] == col:
                return False
        return True

    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1 for _ in range(n)]

        for i in range(n):
            if color[i] == -1:
                if self.dfs(i, 0, color, graph) == False:
                    return False

        return True
