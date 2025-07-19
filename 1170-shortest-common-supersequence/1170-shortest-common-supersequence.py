class Solution:
    def LCS(self, i, j, str1, str2, dp):
        if i == 0 or j == 0:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        if str1[i-1] == str2[j-1]:
            dp[i][j] = 1 + self.LCS(i-1, j-1, str1, str2, dp)
            return dp[i][j]
        
        dp[i][j] = max(self.LCS(i-1, j, str1, str2, dp), self.LCS(i, j-1, str1, str2, dp))
        
        return dp[i][j]

    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        n = len(str1)
        m = len(str2)
        dp = [[-1 for _ in range(m+1)] for _ in range(n+1)]

        dummy = self.LCS(n,m,str1, str2,dp)

        i = n
        j = m

        ans = ""

        while i > 0 and j > 0:
            if str1[i-1] == str2[j-1]:
                ans += str1[i-1]
                i-=1
                j-=1
            elif dp[i-1][j] > dp[i][j-1]:
                ans += str1[i-1]
                i-=1
            else:
                ans += str2[j-1]
                j-=1
        
        while i > 0:
            ans += str1[i-1]
            i-=1

        while j > 0:
            ans += str2[j-1]
            j-=1

        return ans[::-1]


