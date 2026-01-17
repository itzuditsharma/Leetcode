class Solution:
    def helper(self, i, j, dp, matrix):
        if i < 0 or j < 0:
            return 0
        if dp[i][j] != -1:
            return dp[i][j]
        
        left = self.helper(i, j-1, dp, matrix)
        top = self.helper(i-1, j , dp, matrix)
        diag = self.helper(i-1, j-1, dp, matrix)

        if matrix[i][j] == "1":
            dp[i][j] = 1 + min(left, top, diag)
            self.maxi = max(self.maxi, dp[i][j])
        else:
            dp[i][j] = 0
        
        return dp[i][j]

    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n, m = len(matrix), len(matrix[0])
        dp = [[-1] * m for _ in range(n)]
        self.maxi = 0
        self.helper(n-1, m-1, dp, matrix)
        return self.maxi*self.maxi