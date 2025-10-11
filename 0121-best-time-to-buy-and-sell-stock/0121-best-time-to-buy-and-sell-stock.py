class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minday = prices[0]
        maxprofit = 0
        for i in range(1, len(prices)):
            profit = prices[i] - minday
            maxprofit = max(maxprofit, profit)
            if prices[i] < minday:
                minday = prices[i]
        
        return maxprofit