class Solution:
    def helper(self,i,j,str1, str2, dp):
        if j < 0:
            return 1
        if i < 0:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        if str1[i] == str2[j]:
            dp[i][j] = self.helper(i-1, j-1, str1, str2, dp) + self.helper(i-1, j, str1, str2, dp)
            return dp[i][j]
        
        dp[i][j] = self.helper(i-1, j, str1, str2, dp)

        return dp[i][j]

    def numDistinct(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)
        dp = [[-1 for _ in range(m+1)] for _ in range(n+1)]
        return self.helper(n-1, m-1, s, t, dp)