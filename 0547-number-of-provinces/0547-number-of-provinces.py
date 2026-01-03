class Solution:
    def dfs(self, i, vis, adjls):
        vis[i] = 1

        for it in adjls[i]:
            if vis[it] == 0:
                self.dfs(it, vis, adjls)

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        vis = [0] * n

        adjls = [[] for _ in range(n)]

        for i in range(n):
            for j in range(n):
                if isConnected[i][j] == 1 and i != j:
                    adjls[i].append(j)
                    adjls[j].append(i)
        
        provinces = 0
        for i in range(n):
            if vis[i] == 0:
                self.dfs(i, vis, adjls)
                provinces += 1
        
        return provinces