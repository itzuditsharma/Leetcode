class Solution:
    def helper(self, row, col, dp, matrix):
        if row < 0 or col < 0:
            return 0
        
        if dp[row][col] != -1:
            return dp[row][col]
        
        left = self.helper(row, col - 1, dp, matrix)
        diagonal_left = self.helper(row-1, col-1, dp, matrix)
        top = self.helper(row-1, col, dp, matrix)

        if matrix[row][col] == "1":
            dp[row][col]  = 1 + min(left, min(diagonal_left, top))
            self.maxi = max(self.maxi, dp[row][col])
        else:
            dp[row][col] = 0
        
        return dp[row][col]

    def maximalSquare(self, matrix: List[List[str]]) -> int:
        self.maxi = 0
        n = len(matrix)
        m = len(matrix[0])
        dp = [[-1] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                self.helper(i, j, dp, matrix)
        return self.maxi*self.maxi