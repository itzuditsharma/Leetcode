class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = [[] for _ in range(n+1)]
        for u,v,time in times:
            adj[u].append((v, time))

        dist = [float('inf')] * (n+1)
        dist[k] = 0
        pq = []
        pq.append((0,k))

        while pq:
            cost, node = heapq.heappop(pq)
            if cost > dist[node]:
                continue
            
            for adjNode, edw in adj[node]:
                if dist[adjNode] > edw + cost:
                    dist[adjNode] = edw + cost
                    heapq.heappush(pq, (edw + cost, adjNode))
            
        ans = max(dist[1:]) 
        return ans if ans < float('inf') else -1