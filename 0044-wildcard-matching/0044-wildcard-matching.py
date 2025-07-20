class Solution:
    def matching(self, i, j, s, pattern, dp):
        if i < 0 and j < 0:
            return True
        if i < 0 and j >=0:
            return False
        if i >=0 and j < 0:
            for it in range(i+1):
                if pattern[it] != '*':
                    return False
            return True
        

        if dp[i][j] != -1:
            return dp[i][j]

        if pattern[i] == s[j] or pattern[i] == '?':
            dp[i][j] = self.matching(i-1, j-1, s, pattern, dp)
            return dp[i][j]

        if pattern[i] == '*':
            dp[i][j] = self.matching(i-1, j, s, pattern, dp) or self.matching(i, j-1, s, pattern, dp)
            return dp[i][j]

        dp[i][j] = False
        return dp[i][j]

    def isMatch(self, s: str, p: str) -> bool:
        n = len(p)
        m = len(s)
        dp = [[-1 for _ in range(m)] for _ in range(n)]
        return self.matching(n-1, m-1, s, p, dp)