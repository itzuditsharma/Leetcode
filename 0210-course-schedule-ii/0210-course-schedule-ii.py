from collections import deque
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        for u,v in prerequisites:
            adj[v].append(u)
        
        q = deque()
        indegree = [0] * numCourses

        for i in range(numCourses):
            for val in adj[i]:
                indegree[val] += 1
        
        for i in range(len(indegree)):
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
        
        if len(topo) == numCourses:
            return topo
        else:
            return []