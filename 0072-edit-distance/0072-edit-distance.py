class Solution:
    def findDistance(self, i, j, word1, word2, dp):
        if i < 0:
            return j+1
        if j < 0:
            return i+1

        if dp[i][j] != -1:
            return dp[i][j]

        if word1[i] == word2[j]:
            dp[i][j] = 0 + self.findDistance(i-1, j-1, word1, word2, dp)
            return dp[i][j]
        
        dp[i][j] = 1 + min(self.findDistance(i-1, j, word1, word2, dp), self.findDistance(i, j-1, word1, word2, dp), self.findDistance(i-1, j-1, word1, word2, dp))

        return dp[i][j]

    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)

        dp = [[-1 for _ in range(m+1)] for _ in range(n)]

        return self.findDistance(n-1, m-1, word1, word2, dp)