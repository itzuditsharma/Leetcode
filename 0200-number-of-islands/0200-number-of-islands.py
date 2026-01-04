class Solution:
    def dfs(self, row, col, grid, vis, drow, dcol):
        vis[row][col] = 1
        n = len(grid)
        m = len(grid[0])

        for i in range(4):
            nrow = row + drow[i]
            ncol = col + dcol[i]

            if nrow >=0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] == 0 and grid[nrow][ncol] == "1":
                self.dfs(nrow, ncol, grid, vis, drow, dcol)

    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])
        vis = [[0] * m for _ in range(n)]
        drow = [-1, 0, 1, 0]
        dcol = [0, 1, 0, -1]
        count = 0

        for i in range(n):
            for j in range(m):
                if vis[i][j] == 0 and grid[i][j] == "1":
                    count += 1
                    self.dfs(i, j, grid, vis, drow, dcol)
        
        return count