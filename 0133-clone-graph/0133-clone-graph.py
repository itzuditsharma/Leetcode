"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        
        visited = {}

        def dfs(node, visited):
            if node in visited:
                return visited[node]
        
            copy = Node(node.val)

            visited[node] = copy

            for neighbour in node.neighbors:
                copy_neighbour = dfs(neighbour, visited)
                copy.neighbors.append(copy_neighbour)
            
            return copy

        return dfs(node, visited)