class Solution:
    def helper(self, i, coins, dp, amount):
        if i == 0:
            if amount % coins[i] == 0:
                return amount // coins[i]
            return 10**9
        

        if dp[i][amount] != -1:
            return dp[i][amount]
        notTake = self.helper(i-1, coins, dp, amount)
        take = 1e9
        if amount >= coins[i]:
            take = 1 + self.helper(i, coins, dp, amount - coins[i])
        
        dp[i][amount] = min(take, notTake)
        return dp[i][amount]

    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[-1 for _ in range(amount + 1)] for _ in range(n)]
        ans = self.helper(n-1, coins, dp, amount)
        return -1 if ans >= 10**9 else ans
