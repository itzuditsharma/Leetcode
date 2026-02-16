class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        revGraph = [[] for _ in range(n)]
        indegree = [0] * n
        for i in range(n):
            for it in graph[i]:
                revGraph[it].append(i)
                indegree[i] += 1

        
        q = deque()

        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
        
        safenodes = []
        while q:
            node = q.pop()
            safenodes.append(node)

            for it in revGraph[node]:
                indegree[it] -= 1
                if indegree[it] == 0:
                    q.append(it)
        
        return sorted(safenodes)
        
