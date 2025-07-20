class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # N^2
        maxprofit = 0
        n = len(prices)
        for i in range(n):
            for j in range(i+1, n):
                maxprofit = max(maxprofit, prices[j] - prices[i])
        
        return maxprofit