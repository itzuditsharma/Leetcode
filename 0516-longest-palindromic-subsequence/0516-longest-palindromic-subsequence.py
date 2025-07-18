class Solution:
    def LCS(self, word1, word2, i, j, dp):
        if i < 0 or j < 0:
            return 0
        
        if dp[i][j] != -1:
            return dp[i][j]
        if word1[i] == word2[j]:
            return 1 + self.LCS(word1, word2, i-1, j-1, dp)
        
        dp[i][j] = max(self.LCS(word1, word2, i-1, j, dp), self.LCS(word1, word2, i, j-1, dp))
        
        return dp[i][j]
        
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        s2 = s[::-1]
        dp = [[-1 for i in range(n)] for _ in range(n)]
        return self.LCS(s, s2, n-1, n-1, dp)
