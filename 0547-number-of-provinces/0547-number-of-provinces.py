class Solution:
    def dfs(self, node, vis, adj):
        vis[node] = 1

        for it in adj[node]:
            if vis[it] == 0:
                self.dfs(it, vis, adj)

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        vis = [0] * n
        adj = [[] for _ in range(n)]
        
        for i in range(n):
            for j in range(n):
                if isConnected[i][j] == 1 and i != j:
                    adj[i].append(j)
                    adj[j].append(i)

        count = 0
        for i in range(n):
            if vis[i] == 0:
                self.dfs(i, vis, adj)
                count += 1
        
        return count