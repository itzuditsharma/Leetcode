class Solution:
    def climbStairsHelper(self, n: int, dp) -> int:
        if n < 0:
            return 0
        if n == 0:
            return 1
        
        if dp[n] != -1:
            return dp[n]
        dp[n] = self.climbStairsHelper(n-1, dp) + self.climbStairsHelper(n-2, dp)
        return dp[n]

    def climbStairs(self, n: int) -> int:
        dp = [-1 for _ in range(n+1)]
        return self.climbStairsHelper(n,dp)