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

        dp = [[-1 for _ in range(m)] for _ in range(n)]

        lcs = self.findLCS(n-1, m-1, word1, word2, dp)

        insertions = n - lcs
        deletions = m - lcs

        return insertions + deletions