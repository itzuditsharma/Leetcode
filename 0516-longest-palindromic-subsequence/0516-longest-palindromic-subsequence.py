class Solution:
    def findLCS(self, i, j, str1, str2, dp):
        if i < 0 or j < 0:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]
        
        if str1[i] == str2[j]:
            return 1 + self.findLCS(i-1, j-1, str1, str2, dp)

        dp[i][j] = max(self.findLCS(i-1, j, str1, str2, dp), self.findLCS(i, j-1, str1, str2, dp))
        return dp[i][j]

    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        s1 = s
        s2 = s[::-1]

        dp = [[-1 for _ in range(n)] for _ in range(n)]

        lcs = self.findLCS(n-1,n-1,s1,s2,dp)
        return lcs