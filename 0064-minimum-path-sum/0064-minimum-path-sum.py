class Solution:
    def mps(self, i, j , grid, dp):
        if i == 0 and j == 0:
            return grid[i][j]
        if j < 0 or i < 0:
            return 1e8
        
        if dp[i][j] != -1:
            return dp[i][j]

        top = grid[i][j] + self.mps(i-1, j, grid, dp)
        left = grid[i][j] + self.mps(i, j-1, grid, dp)

        dp[i][j] = min(top, left)
        return dp[i][j]
        


    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dp = [[-1 for _ in range(m)] for _ in range(n)]
        return self.mps(n-1, m-1, grid, dp)