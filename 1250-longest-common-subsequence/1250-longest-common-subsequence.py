class Solution:
    def lcs(self, i, j, text1, text2, dp):
        if i == 0 or j == 0:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]
        
        if text1[i-1] == text2[j-1]:
            return 1 + self.lcs(i-1, j-1, text1, text2, dp)
        
        dp[i][j] = max(self.lcs(i-1, j, text1, text2, dp), self.lcs(i, j-1, text1, text2, dp))
        return dp[i][j]

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1)
        m = len(text2)

        dp = [[-1 for _ in range(m+1)] for _ in range(n+1)]

        return self.lcs(n, m, text1, text2, dp)