class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        q = deque()
        time = 0

        vis = [[0] * m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    vis[i][j] = 2
                    q.append(((i,j), 0))
        
        drow = [-1, 0, 1, 0]
        dcol = [0, 1, 0, -1]

        while q:
            (row, col), t = q.popleft()
            time = max(time, t)

            for i in range(4):
                nrow = row + drow[i]
                ncol = col + dcol[i]

                if nrow >= 0 and nrow < n and ncol >=0 and ncol < m and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1:
                    vis[nrow][ncol] = 2
                    q.append(((nrow, ncol), t+1))

        for i in range(n):
            for j in range(m):
                if vis[i][j] != 2 and grid[i][j] == 1:
                    return -1
        
        return time
