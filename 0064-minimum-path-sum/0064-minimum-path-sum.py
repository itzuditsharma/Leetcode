class Solution:
    def helper(self, i, j , grid, dp):
        if i == 0 and j == 0:
            return grid[i][j]
        if i < 0 or j < 0:
            return 1e9

        if dp[i][j] != -1:
            return dp[i][j]

        up = grid[i][j] +  self.helper(i-1, j, grid, dp)
        left = grid[i][j] + self.helper(i, j-1, grid, dp)

        dp[i][j] = min(up, left)
        return dp[i][j]

    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dp = [[-1] * m for _ in range(n)]
        return self.helper(n-1, m-1, grid, dp)