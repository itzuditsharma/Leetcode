class Solution:
    def findLCS(self, i, j , word1, word2, dp):
        if i < 0 or j < 0:
            return 0
        
        if dp[i][j] != -1:
            return dp[i][j]
        
        if word1[i] == word2[j]:
            return 1 + self.findLCS(i-1, j-1, word1, word2, dp)
        
        dp[i][j] = max(self.findLCS(i-1, j, word1, word2, dp), self.findLCS(i, j-1, word1, word2, dp))

        return dp[i][j]

    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)

        dp = [[0 for _ in range(m+1)] for _ in range(n+1)]

        for i in range(1, n+1):
            for j in range(1, m+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        lcs = dp[n][m]

        insertions = n - lcs
        deletions = m - lcs

        return insertions + deletions