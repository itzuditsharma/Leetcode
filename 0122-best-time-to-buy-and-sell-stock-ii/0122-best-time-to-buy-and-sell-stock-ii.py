class Solution:
    def helper(self, i, buy, prices, n, dp):
        if i == n:
            return 0

        if dp[i][buy] != -1:
            return dp[i][buy]

        profit = 0

        if buy == 1:
            profit = max((-prices[i] + self.helper(i + 1, 0, prices, n, dp)), (0 + self.helper(i+1, 1, prices, n, dp))) 
        else:
            profit = max((prices[i] + self.helper(i + 1, 1, prices, n, dp)), (0 + self.helper(i+1, 0, prices, n, dp)))
        
        dp[i][buy] = profit
        return dp[i][buy] 

    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[-1 for _ in range(2)] for _ in range(n)]
        return self.helper(0, 1, prices, n, dp) 