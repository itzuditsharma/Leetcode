class Solution:
    def findMatch(self, i, j, s, p, dp):
        if i < 0 and j < 0:
            return True
        if i < 0 and j >= 0:
            return False
        if i >= 0 and j < 0:
            for it in range(i+1):
                if p[it] != '*':
                    return False
            return True

        if dp[i][j] != -1:
            return dp[i][j]

        if p[i] == s[j] or p[i] == '?':
            dp[i][j] = self.findMatch(i-1, j-1, s, p, dp)
            return dp[i][j]
        
        if p[i] == '*':
            dp[i][j] = self.findMatch(i, j-1, s, p, dp) or self.findMatch(i-1, j, s, p, dp)
            return dp[i][j]

        dp[i][j] = False

        return dp[i][j]

    def isMatch(self, s: str, p: str) -> bool:
        n = len(p)
        m = len(s)

        dp = [[-1 for _ in range(m+1)] for _ in range(n+1)]

        return self.findMatch(n-1, m-1, s, p, dp)