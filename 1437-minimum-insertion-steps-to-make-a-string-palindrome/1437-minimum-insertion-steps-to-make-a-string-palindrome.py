class Solution:
    def LCS(self, i, j, word1, word2, dp):
        if i < 0 or j < 0:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        if word1[i] == word2[j]:
            dp[i][j] =  1 + self.LCS(i-1, j-1, word1, word2, dp)
            return dp[i][j]
        
        dp[i][j] = max(self.LCS(i-1, j, word1, word2, dp), self.LCS(i, j-1, word1, word2, dp))

        return dp[i][j]

    def minInsertions(self, s: str) -> int:
        n = len(s)
        s2 = s[::-1]
        dp = [[-1 for _ in range(n+1)] for _ in range(n+1)]
        no_of_insertions = self.LCS(n-1, n-1, s, s2, dp)
        return n - no_of_insertions

