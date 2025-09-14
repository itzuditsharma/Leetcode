class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit = 0
        mini = prices[0]
        for i in range(1, len(prices)):
            cost = prices[i] - mini
            maxprofit = max(maxprofit,cost)
            mini = min(mini, prices[i])

        return maxprofit