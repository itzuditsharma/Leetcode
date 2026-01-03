class Solution:
    def dfs(self, row, col, vis, board, drow, dcol):
        vis[row][col] = 1
        n = len(board)
        m = len(board[0])

        for i in range(4):
            nrow = row + drow[i]
            ncol = col + dcol[i]

            if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] == 0 and board[nrow][ncol] == 'O':
                self.dfs(nrow, ncol, vis, board, drow, dcol)

    def solve(self, board: List[List[str]]) -> None:
        n = len(board)
        m = len(board[0])
        vis = [[0] * m for _ in range(n)]
        drow = [-1, 0, 1, 0]
        dcol = [0, 1, 0, -1]

        for i in range(m):
            if board[0][i] == 'O' and vis[0][i] == 0:
                self.dfs(0, i, vis, board, drow, dcol)
            if board[n-1][i] == 'O' and vis[n-1][i] == 0:
                self.dfs(n-1, i, vis, board, drow, dcol)

        for i in range(n):
            if board[i][0] == 'O' and vis[i][0] == 0:
                self.dfs(i, 0, vis, board, drow, dcol)
            if board[i][m-1] == 'O' and vis[i][m-1] == 0:
                self.dfs(i, m-1, vis, board, drow, dcol)
        
        for i in range(n):
            for j in range(m):
                if vis[i][j] == 0 and board[i][j] == 'O':
                    board[i][j] = 'X'

        