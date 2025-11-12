class Solution:
    def helper(self, i, j, k, s1, s2, s3, dp):
        if i == len(s1) and j == len(s2) and k == len(s3):
            return True

        if dp[i][j] != -1:
            return dp[i][j]

        x = False
        y = False
        if i < len(s1):
            if s1[i] == s3[k]:
                x = self.helper(i+1, j, k+1, s1, s2, s3, dp)
        
        if j < len(s2):
            if s2[j] == s3[k]:
                y = self.helper(i, j+1, k+1, s1, s2, s3, dp)
        
        dp[i][j] = x or y
        return dp[i][j]

    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        a = len(s1)
        b = len(s2)
        i,j,k = 0,0,0
        dp = [[-1 for _ in range(b+1)] for _ in range(a+1)]
        return self.helper(0,0,0,s1, s2, s3, dp)
