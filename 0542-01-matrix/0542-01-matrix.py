class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n = len(mat)
        m = len(mat[0])
        vis = [[0] * m for _ in range(n)]
        ans = [[0] * m for _ in range(n)]
        q = deque()

        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    vis[i][j] = 1
                    q.append(((i, j), 0))

        drow = [-1, 0, 1, 0]
        dcol = [0, 1, 0, -1]

        while q:
            (row, col), time = q.popleft()
            ans[row][col] = time

            for i in range(4):
                nrow = row + drow[i]
                ncol = col + dcol[i]

                if nrow >= 0 and nrow < n and ncol >=0 and ncol < m and mat[nrow][ncol] != 0 and vis[nrow][ncol] == 0:
                    vis[nrow][ncol] = 1
                    q.append(((nrow, ncol), time + 1))
        
        return ans
