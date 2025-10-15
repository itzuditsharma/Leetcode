class Solution:
    def helper(self, i, j, text1, text2, dp):
        if i < 0 or j < 0:
            return 0
        
        if dp[i][j] != -1:
            return dp[i][j]

        if text1[i] == text2[j]:
            dp[i][j] = 1 + self.helper(i-1, j-1, text1, text2, dp)
            return dp[i][j]
        
        dp[i][j] = max(self.helper(i-1, j, text1, text2, dp), self.helper(i, j-1, text1, text2, dp))

        return dp[i][j]

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1)
        m = len(text2)
        dp = [[-1 for _ in range(m)] for _ in range(n)]
        return self.helper(n-1, m-1, text1, text2, dp)