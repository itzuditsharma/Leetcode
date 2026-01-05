class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        n = numCourses
        adj = [[] for _ in range(n)]
        indegree = [0 for _ in range(n)]

        for u, v in prerequisites:
            adj[v].append(u)
        
        for i in range(n):
            for it in adj[i]:
                indegree[it] += 1
        
        q = deque()
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)

        topo = []    
        while q:
            node = q.popleft()
            topo.append(node)
            for it in adj[node]:
                indegree[it] -= 1
                if indegree[it] == 0:
                    q.append(it)

        if len(topo) == n:
            return True
        return False
